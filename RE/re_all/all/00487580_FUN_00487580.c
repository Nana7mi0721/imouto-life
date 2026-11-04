
uint __thiscall FUN_00487580(int param_1,uint param_2)

{
  char cVar1;
  uint uVar3;
  uint uVar2;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_80;
  int local_7c;
  uint local_78;
  uint local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_5c;
  int local_58;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if (*(int *)(param_1 + 0x1b4) < 1) {
    local_58 = 1;
  }
  else {
    local_58 = *(int *)(param_1 + 0x1b4);
  }
  if (*(int *)(param_1 + 0x1b0) < 0) {
    local_5c = 0;
  }
  else {
    local_5c = *(int *)(param_1 + 0x1b0);
  }
  if (param_2 < 0x15) {
    uVar2 = DAT_00a17ebc >> 0x1f;
    uVar3 = DAT_00a17ec0 >> 0x1f;
    switch(param_2) {
    case 0:
      if (*(char *)(param_1 + 0x240) == '\0') {
        if (*(char *)(param_1 + 0x266) == '\0') {
          local_68 = 0;
        }
        else {
          local_68 = (int)(DAT_00a17ebc + (uVar2 & 3)) >> 2;
        }
        local_b4 = ((*(int *)(param_1 + 0x188) +
                    ((*(int *)(param_1 + 0x18c) - *(int *)(param_1 + 0x188)) * local_5c) / local_58)
                   - local_68) + *(int *)(param_1 + 0x1f8);
      }
      else {
        local_10 = 0;
        for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
          local_10 = *(int *)(param_1 + 0x200 + local_14 * 4) +
                     ((*(int *)(param_1 + 0x210 + local_14 * 4) -
                      *(int *)(param_1 + 0x200 + local_14 * 4)) * local_5c) / local_58 + local_10;
        }
        if (*(char *)(param_1 + 0x266) == '\0') {
          local_64 = 0;
        }
        else {
          local_64 = (int)(DAT_00a17ebc + (uVar2 & 3)) >> 2;
        }
        local_b4 = (((int)(local_10 + (local_10 >> 0x1f & 3U)) >> 2) - local_64) +
                   *(int *)(param_1 + 0x1f8);
      }
      break;
    case 1:
      if (*(char *)(param_1 + 0x240) == '\0') {
        if (*(char *)(param_1 + 0x266) == '\0') {
          local_70 = 0;
        }
        else {
          local_70 = (int)(DAT_00a17ec0 + (uVar3 & 3)) >> 2;
        }
        local_b4 = ((*(int *)(param_1 + 400) +
                    ((*(int *)(param_1 + 0x194) - *(int *)(param_1 + 400)) * local_5c) / local_58) -
                   local_70) + *(int *)(param_1 + 0x1fc);
      }
      else {
        local_18 = 0;
        for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
          local_18 = *(int *)(param_1 + 0x220 + local_1c * 4) +
                     ((*(int *)(param_1 + 0x230 + local_1c * 4) -
                      *(int *)(param_1 + 0x220 + local_1c * 4)) * local_5c) / local_58 + local_18;
        }
        if (*(char *)(param_1 + 0x266) == '\0') {
          local_6c = 0;
        }
        else {
          local_6c = (int)(DAT_00a17ec0 + (uVar3 & 3)) >> 2;
        }
        local_b4 = (((int)(local_18 + (local_18 >> 0x1f & 3U)) >> 2) - local_6c) +
                   *(int *)(param_1 + 0x1fc);
      }
      break;
    case 2:
      if (*(char *)(param_1 + 0x265) == '\0') {
        local_74 = *(uint *)(param_1 + 0x1c0);
      }
      else {
        local_74 = (*(int *)(param_1 + 0x270) * *(int *)(param_1 + 0x1d0)) / 100;
      }
      local_b4 = local_74;
      break;
    case 3:
      if (*(char *)(param_1 + 0x265) == '\0') {
        local_78 = *(uint *)(param_1 + 0x1c8);
      }
      else {
        local_78 = (*(int *)(param_1 + 0x274) * *(int *)(param_1 + 0x1d8)) / 100;
      }
      local_b4 = local_78;
      break;
    case 4:
      local_b4 = *(uint *)(param_1 + 0x198);
      break;
    case 5:
      local_b4 = ((*(int *)(param_1 + 0x1a4) - *(int *)(param_1 + 0x1a0)) * local_5c) / local_58 +
                 *(int *)(param_1 + 0x1a0);
      break;
    case 6:
      local_b4 = ((*(int *)(param_1 + 0x1bc) - *(int *)(param_1 + 0x1b8)) * local_5c) / local_58 +
                 *(int *)(param_1 + 0x1b8);
      break;
    case 7:
      if (((*(int *)(param_1 + 0x1d4) - *(int *)(param_1 + 0x1d0)) * local_5c) / local_58 +
          *(int *)(param_1 + 0x1d0) == 100) {
        local_b4 = ((*(int *)(param_1 + 0x1dc) - *(int *)(param_1 + 0x1d8)) * local_5c) / local_58 +
                   *(int *)(param_1 + 0x1d8);
      }
      else {
        local_b4 = ((*(int *)(param_1 + 0x1d4) - *(int *)(param_1 + 0x1d0)) * local_5c) / local_58 +
                   *(int *)(param_1 + 0x1d0);
      }
      break;
    case 8:
      if (*(char *)(param_1 + 0x279) == '\0') {
        FUN_00488310(0);
        local_24 = 999999;
        local_20 = 999999;
        local_28 = -999999;
        local_2c = -999999;
        if (*(char *)(param_1 + 0x240) == '\0') {
          if (*(int *)(param_1 + 0x27c) < *(int *)(param_1 + 0x280)) {
            local_9c = *(int *)(param_1 + 0x27c);
          }
          else {
            local_9c = *(int *)(param_1 + 0x280);
          }
          if (local_9c <= DAT_00a14620) {
            if (*(int *)(param_1 + 0x27c) < *(int *)(param_1 + 0x280)) {
              local_a0 = *(int *)(param_1 + 0x280);
            }
            else {
              local_a0 = *(int *)(param_1 + 0x27c);
            }
            if (DAT_00a14620 <= local_a0) {
              if (*(int *)(param_1 + 0x284) < *(int *)(param_1 + 0x288)) {
                local_a4 = *(int *)(param_1 + 0x284);
              }
              else {
                local_a4 = *(int *)(param_1 + 0x288);
              }
              if (local_a4 <= DAT_00a14624) {
                if (*(int *)(param_1 + 0x288) < *(int *)(param_1 + 0x284)) {
                  local_a8 = *(int *)(param_1 + 0x284);
                }
                else {
                  local_a8 = *(int *)(param_1 + 0x288);
                }
                if (DAT_00a14624 <= local_a8) {
                  return 1;
                }
              }
            }
          }
        }
        else {
          for (local_30 = 0; local_30 < 2; local_30 = local_30 + 1) {
            if (local_24 < *(int *)(param_1 + 0x28c + local_30 * 4)) {
              local_7c = local_24;
            }
            else {
              local_7c = *(int *)(param_1 + 0x28c + local_30 * 4);
            }
            if (local_7c < *(int *)(param_1 + 0x294 + local_30 * 4)) {
              local_80 = local_7c;
            }
            else {
              local_80 = *(int *)(param_1 + 0x294 + local_30 * 4);
            }
            local_24 = local_80;
            if (*(int *)(param_1 + 0x294 + local_30 * 4) < local_80) {
              local_88 = local_80;
            }
            else {
              local_88 = *(int *)(param_1 + 0x294 + local_30 * 4);
            }
            local_28 = local_88;
            if (local_20 < *(int *)(param_1 + 0x29c + local_30 * 4)) {
              local_8c = local_20;
            }
            else {
              local_8c = *(int *)(param_1 + 0x29c + local_30 * 4);
            }
            if (local_8c < *(int *)(param_1 + 0x2a4 + local_30 * 4)) {
              local_90 = local_8c;
            }
            else {
              local_90 = *(int *)(param_1 + 0x2a4 + local_30 * 4);
            }
            local_20 = local_90;
            if (*(int *)(param_1 + 0x29c + local_30 * 4) < local_2c) {
              local_94 = local_2c;
            }
            else {
              local_94 = *(int *)(param_1 + 0x29c + local_30 * 4);
            }
            if (*(int *)(param_1 + 0x2a4 + local_30 * 4) < local_94) {
              local_98 = local_94;
            }
            else {
              local_98 = *(int *)(param_1 + 0x2a4 + local_30 * 4);
            }
            local_2c = local_98;
          }
          if ((((local_24 <= DAT_00a14620) && (DAT_00a14620 <= local_28)) &&
              (local_20 <= DAT_00a14624)) && (DAT_00a14624 <= local_2c)) {
            return 1;
          }
        }
      }
      local_b4 = 0;
      break;
    case 9:
      if (*(char *)(param_1 + 0x279) == '\0') {
        if ((*(char *)(param_1 + 0x278) == '\0') || (0 < *(int *)(param_1 + 0x1b0))) {
          local_b0 = 1;
        }
        else {
          local_b0 = 0;
        }
        local_ac = local_b0;
      }
      else {
        local_ac = 0;
      }
      local_b4 = local_ac;
      break;
    case 10:
      if (*(char *)(param_1 + 0x264) == '\0') {
        local_b4 = 0xffffffff;
      }
      else {
        cVar1 = FUN_00488290();
        local_b4 = (uint)(cVar1 != '\0');
      }
      break;
    case 0xb:
      local_b4 = ((*(int *)(param_1 + 0x1d4) - *(int *)(param_1 + 0x1d0)) * local_5c) / local_58 +
                 *(int *)(param_1 + 0x1d0);
      break;
    case 0xc:
      local_b4 = ((*(int *)(param_1 + 0x1dc) - *(int *)(param_1 + 0x1d8)) * local_5c) / local_58 +
                 *(int *)(param_1 + 0x1d8);
      break;
    case 0xd:
      if (*(char *)(param_1 + 0x240) == '\0') {
        local_b4 = 0xffffffff;
      }
      else {
        if (*(char *)(param_1 + 0x266) == '\0') {
          local_b8 = 0;
        }
        else {
          local_b8 = (int)(DAT_00a17ebc + (uVar2 & 3)) >> 2;
        }
        local_b4 = (*(int *)(param_1 + 0x200) +
                   ((*(int *)(param_1 + 0x210) - *(int *)(param_1 + 0x200)) * local_5c) / local_58)
                   - local_b8;
      }
      break;
    case 0xe:
      if (*(char *)(param_1 + 0x240) == '\0') {
        local_b4 = 0xffffffff;
      }
      else {
        if (*(char *)(param_1 + 0x266) == '\0') {
          local_bc = 0;
        }
        else {
          local_bc = (int)(DAT_00a17ec0 + (uVar3 & 3)) >> 2;
        }
        local_b4 = (*(int *)(param_1 + 0x220) +
                   ((*(int *)(param_1 + 0x230) - *(int *)(param_1 + 0x220)) * local_5c) / local_58)
                   - local_bc;
      }
      break;
    case 0xf:
      if (*(char *)(param_1 + 0x240) == '\0') {
        local_b4 = 0xffffffff;
      }
      else {
        if (*(char *)(param_1 + 0x266) == '\0') {
          local_c0 = 0;
        }
        else {
          local_c0 = (int)(DAT_00a17ebc + (uVar2 & 3)) >> 2;
        }
        local_b4 = (*(int *)(param_1 + 0x204) +
                   ((*(int *)(param_1 + 0x214) - *(int *)(param_1 + 0x204)) * local_5c) / local_58)
                   - local_c0;
      }
      break;
    case 0x10:
      if (*(char *)(param_1 + 0x240) == '\0') {
        local_b4 = 0xffffffff;
      }
      else {
        if (*(char *)(param_1 + 0x266) == '\0') {
          local_c4 = 0;
        }
        else {
          local_c4 = (int)(DAT_00a17ec0 + (uVar3 & 3)) >> 2;
        }
        local_b4 = (*(int *)(param_1 + 0x224) +
                   ((*(int *)(param_1 + 0x234) - *(int *)(param_1 + 0x224)) * local_5c) / local_58)
                   - local_c4;
      }
      break;
    case 0x11:
      if (*(char *)(param_1 + 0x240) == '\0') {
        local_b4 = 0xffffffff;
      }
      else {
        if (*(char *)(param_1 + 0x266) == '\0') {
          local_c8 = 0;
        }
        else {
          local_c8 = (int)(DAT_00a17ebc + (uVar2 & 3)) >> 2;
        }
        local_b4 = (*(int *)(param_1 + 0x208) +
                   ((*(int *)(param_1 + 0x218) - *(int *)(param_1 + 0x208)) * local_5c) / local_58)
                   - local_c8;
      }
      break;
    case 0x12:
      if (*(char *)(param_1 + 0x240) == '\0') {
        local_b4 = 0xffffffff;
      }
      else {
        if (*(char *)(param_1 + 0x266) == '\0') {
          local_cc = 0;
        }
        else {
          local_cc = (int)(DAT_00a17ec0 + (uVar3 & 3)) >> 2;
        }
        local_b4 = (*(int *)(param_1 + 0x228) +
                   ((*(int *)(param_1 + 0x238) - *(int *)(param_1 + 0x228)) * local_5c) / local_58)
                   - local_cc;
      }
      break;
    case 0x13:
      if (*(char *)(param_1 + 0x240) == '\0') {
        local_b4 = 0xffffffff;
      }
      else {
        if (*(char *)(param_1 + 0x266) == '\0') {
          local_d0 = 0;
        }
        else {
          local_d0 = (int)(DAT_00a17ebc + (uVar2 & 3)) >> 2;
        }
        local_b4 = (*(int *)(param_1 + 0x20c) +
                   ((*(int *)(param_1 + 0x21c) - *(int *)(param_1 + 0x20c)) * local_5c) / local_58)
                   - local_d0;
      }
      break;
    case 0x14:
      if (*(char *)(param_1 + 0x240) == '\0') {
        local_b4 = 0xffffffff;
      }
      else {
        if (*(char *)(param_1 + 0x266) == '\0') {
          local_d4 = 0;
        }
        else {
          local_d4 = (int)(DAT_00a17ec0 + (uVar3 & 3)) >> 2;
        }
        local_b4 = (*(int *)(param_1 + 0x22c) +
                   ((*(int *)(param_1 + 0x23c) - *(int *)(param_1 + 0x22c)) * local_5c) / local_58)
                   - local_d4;
      }
    }
  }
  else {
    local_b4 = 0xffffffff;
  }
  return local_b4;
}

