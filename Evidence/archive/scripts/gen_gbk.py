import io
seen = {}
for cp in range(0x80, 0x10000):
    ch = chr(cp)
    try:
        b = ch.encode('gbk')
    except Exception:
        continue
    if len(b) == 2:
        key = (b[0] << 8) | b[1]
        if key not in seen:
            seen[key] = cp
items = sorted(seen.items())
print('entries', len(items))
lines = []
lines.append('//! GBK (code page 936) decode table, generated from the Standard GBK mapping.')
lines.append('//! The Chinese fan translation stores display strings in GBK even though the')
lines.append('//! container code page is 932.')
lines.append('')
lines.append('/// Decode GBK bytes. Returns the text and whether any byte was unmapped.')
lines.append('pub fn decode(bytes: &[u8]) -> (String, bool) {')
lines.append('    let mut out = String::with_capacity(bytes.len());')
lines.append('    let mut bad = false;')
lines.append('    let mut i = 0;')
lines.append('    while i < bytes.len() {')
lines.append('        let b = bytes[i];')
lines.append('        if b < 0x80 {')
lines.append('            out.push(b as char);')
lines.append('            i += 1;')
lines.append('            continue;')
lines.append('        }')
lines.append('        if i + 1 < bytes.len() {')
lines.append('            let key = (u16::from(b) << 8) | u16::from(bytes[i + 1]);')
lines.append('            match TABLE.binary_search_by_key(&key, |e| e.0) {')
lines.append('                Ok(idx) => {')
lines.append('                    out.push(char::from_u32(u32::from(TABLE[idx].1)).unwrap());')
lines.append('                    i += 2;')
lines.append('                }')
lines.append('                Err(_) => {')
lines.append("                    out.push('\\u{FFFD}');")
lines.append('                    bad = true;')
lines.append('                    i += 1;')
lines.append('                }')
lines.append('            }')
lines.append('        } else {')
lines.append("            out.push('\\u{FFFD}');")
lines.append('            bad = true;')
lines.append('            i += 1;')
lines.append('        }')
lines.append('    }')
lines.append('    (out, bad)')
lines.append('}')
lines.append('')
lines.append('static TABLE: &[(u16, u16)] = &[')
for key, cp in items:
    lines.append('    (0x%04X, 0x%04X),' % (key, cp))
lines.append('];')
with io.open('crates/wolf-format/src/gbk.rs', 'w', encoding='utf-8', newline='') as f:
    f.write('\n'.join(lines) + '\n')
print('written')
