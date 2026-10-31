use std::collections::BTreeMap;
use std::path::PathBuf;
use wolf_format::command::{Command,Slot};
use wolf_format::commonevent::CommonEventData;
use wolf_format::mps::Map;
use wolf_format::sysdatabase::SysDatabase;


fn data_root()->PathBuf{let raw=std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_|"work/Data".to_owned());let p=PathBuf::from(raw);if p.is_absolute(){return p;}let mut b=PathBuf::from(env!("CARGO_MANIFEST_DIR"));b.pop();b.pop();b.join(p)}
fn args(cmd:&Command)->Vec<i32>{cmd.params.chunks_exact(4).map(|c|i32::from_le_bytes([c[0],c[1],c[2],c[3]])).collect()}
fn target(raw:i32)->Option<u32>{match raw{500_000..=599_999=>Some((raw-500_000) as u32),600_000..=699_999=>Some((raw-600_000) as u32),_=>None}}
fn kind(raw:i32)->&'static str{let flags=(raw>>28)as u8&0x0F;let body=raw&0x0FFF_FFFF;if flags!=0{if (1_000_000..3_000_000).contains(&body){kind0(body)}else{"Opaque"}}else{kind0(body)}}
fn kind0(body:i32)->&'static str{match body{0..=999_999=>"Literal",1_000_000..2_000_000=>"SelfVar",2_000_000..3_000_000=>"Var",3_000_000..4_000_000=>"StrVar",9_000_000..=9_999_999=>"SysVar",_=>"Opaque"}}
fn is_storage(raw:i32)->bool{!matches!(kind(raw),"Literal"|"Opaque")}

#[test]
fn probe(){
 let dir=data_root(); assert!(dir.join("BasicData/CommonEvent.dat").is_file(),"no {}",dir.display());
 let bytes=std::fs::read(dir.join("BasicData/CommonEvent.dat")).unwrap();
 let ce=CommonEventData::parse(&bytes).unwrap();
 let mut op210=0; let mut dyn210=Vec::new(); let mut lit210=0; let mut by_kind:BTreeMap<String,usize>=BTreeMap::new();
 let mut ids210:BTreeMap<u32,usize>=BTreeMap::new();
 let mut op211=0; let mut ids211:BTreeMap<u32,usize>=BTreeMap::new(); let mut dyn211=Vec::new();
 let mut op300=0; let mut names300:BTreeMap<String,usize>=BTreeMap::new();
 for ev in &ce.events{
  for (pc,slot) in ev.commands.iter().enumerate(){
   let Slot::Command(c)=slot else{continue};
   match c.opcode{
    210=>{op210+=1; let a=args(c); let raw=a.first().copied().unwrap_or(0); let k=kind(raw); *by_kind.entry(k.to_owned()).or_insert(0)+=1;
      if is_storage(raw){dyn210.push((ev.id,pc,raw,a.clone(),k.to_owned()));} else if let Some(t)=target(raw){lit210+=1;*ids210.entry(t).or_insert(0)+=1;} else {dyn210.push((ev.id,pc,raw,a.clone(),format!("NONLIT {k}")));}
    }
    211=>{op211+=1; let a=args(c); let raw=a.first().copied().unwrap_or(0); let k=kind(raw); if is_storage(raw){dyn211.push((ev.id,pc,raw,k.to_owned()));} else if let Some(t)=target(raw){*ids211.entry(t).or_insert(0)+=1;}}
    300=>{op300+=1; if let Some(s)=c.strings.first(){*names300.entry(s.clone()).or_insert(0)+=1;}}
    _=>{}
   }
  }
 }
 println!("op210 total={op210} literal_targets={lit210} dynamic/other={} kinds={:?}",dyn210.len(),by_kind);
 println!("op210 ids={:?}",ids210);
 println!("op210 dynamic samples={:?}",dyn210.iter().take(30).collect::<Vec<_>>());
 println!("op211 total={op211} ids={ids211:?} dynamic={}",dyn211.len());
 println!("op211 dynamic samples={:?}",dyn211.iter().take(20).collect::<Vec<_>>());
 println!("op300 total={op300} names={:?}",names300);
 // maps
 let sysb=std::fs::read(dir.join("BasicData/SysDatabase.dat")).unwrap();
 let sys=SysDatabase::parse(&sysb).unwrap();
 let maps:Vec<String>=(0..sys.row_count(SysDatabase::MAP_SETTINGS_TYPE)).filter_map(|r|sys.text(SysDatabase::MAP_SETTINGS_TYPE,r,0).map(|s|s.to_owned())).filter(|s|!s.is_empty()).collect();
 println!("registered maps={maps:?}");
 let mut map210=0; let mut map_events=0; let mut map_pages=0; let mut map_calls:BTreeMap<u32,usize>=BTreeMap::new();
 for mp in &maps{
  let bytes=std::fs::read(dir.join(mp)).unwrap(); let map=Map::parse(&bytes).unwrap();
  println!("map {mp}: events={} w={} h={}",map.events.len(),map.width,map.height);
  for e in &map.events{map_events+=1; map_pages+=e.pages.len(); for pg in &e.pages{for slot in &pg.commands{let Slot::Command(c)=slot else{continue}; if c.opcode==210{map210+=1; let a=args(c); let raw=a.first().copied().unwrap_or(0); if let Some(t)=target(raw){*map_calls.entry(t).or_insert(0)+=1;} else {println!(" map210 dyn {} ev{} {:?}",raw,e.id,a);}}}}}
 }
 println!("map events={map_events} pages={map_pages} op210={map210} ids={:?}",map_calls);
 // title ids / names around target claims
 for id in [42u32,549,224,225,226,228,229,237,212]{ if let Some(ev)=ce.event(id){println!("CE{id}: title={:?} cond={} cmds={} op210={}",ev.title,ev.run_condition(),ev.commands.len(),ev.commands.iter().filter(|s|matches!(s,Slot::Command(c) if c.opcode==210)).count());}}
}