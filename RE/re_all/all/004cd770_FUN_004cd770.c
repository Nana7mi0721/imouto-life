
void __thiscall FUN_004cd770(void *param_1,uint param_2)

{
  uint uVar1;
  iterator *this;
  undefined1 *puVar2;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  uVar1 = FUN_004cd730();
  if (uVar1 <= param_2) {
    FID_conflict__Xran(param_1);
  }
  puVar2 = local_c;
  this = (iterator *)FUN_004ce060(local_8);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::iterator::operator+
            (this,(int)puVar2);
  FUN_004d95b0();
  return;
}

