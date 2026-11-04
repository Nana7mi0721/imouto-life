
void __thiscall
FUN_004b8c60(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int local_108;
  int local_104;
  int local_100;
  int local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if (1 < param_6) {
    param_6 = param_6 / DAT_0084b244;
  }
  switch(param_2) {
  case 0:
    if (param_3 / 2 + 100 < 0xc9) {
      local_10 = param_3 / 2 + 100;
    }
    else {
      local_10 = 200;
    }
    if (local_10 < 0) {
      local_14 = 0;
    }
    else {
      if (param_3 / 2 + 100 < 0xc9) {
        local_18 = param_3 / 2 + 100;
      }
      else {
        local_18 = 200;
      }
      local_14 = local_18;
    }
    if (param_4 / 2 + 100 < 0xc9) {
      local_1c = param_4 / 2 + 100;
    }
    else {
      local_1c = 200;
    }
    if (local_1c < 0) {
      local_20 = 0;
    }
    else {
      if (param_4 / 2 + 100 < 0xc9) {
        local_24 = param_4 / 2 + 100;
      }
      else {
        local_24 = 200;
      }
      local_20 = local_24;
    }
    if (param_5 / 2 + 100 < 0xc9) {
      local_28 = param_5 / 2 + 100;
    }
    else {
      local_28 = 200;
    }
    if (local_28 < 0) {
      local_2c = 0;
    }
    else {
      if (param_5 / 2 + 100 < 0xc9) {
        local_30 = param_5 / 2 + 100;
      }
      else {
        local_30 = 200;
      }
      local_2c = local_30;
    }
    *(int *)(param_1 + 0x2b0) = local_20 * 0x100 + local_14 * 0x10000 + local_2c;
    *(int *)(param_1 + 0x2b8) = param_6;
    *(int *)(param_1 + 0x2b4) = param_6;
    break;
  case 1:
    if (*(int *)(param_1 + 0x2c4) < 1) {
      local_34 = 1;
    }
    else {
      local_34 = *(int *)(param_1 + 0x2c4);
    }
    if (((int)(*(int *)(param_1 + 700) + (*(int *)(param_1 + 700) >> 0x1f & 0xffffU)) >> 0x10) -
        ((((int)(*(int *)(param_1 + 700) + (*(int *)(param_1 + 700) >> 0x1f & 0xffffU)) >> 0x10) -
         ((int)(*(int *)(param_1 + 0x2c0) + (*(int *)(param_1 + 0x2c0) >> 0x1f & 0xffffU)) >> 0x10))
        * *(int *)(param_1 + 0x2c8)) / local_34 < 0xc9) {
      if (*(int *)(param_1 + 0x2c4) < 1) {
        local_3c = 1;
      }
      else {
        local_3c = *(int *)(param_1 + 0x2c4);
      }
      local_38 = ((int)(*(int *)(param_1 + 700) + (*(int *)(param_1 + 700) >> 0x1f & 0xffffU)) >>
                 0x10) - ((((int)(*(int *)(param_1 + 700) +
                                 (*(int *)(param_1 + 700) >> 0x1f & 0xffffU)) >> 0x10) -
                          ((int)(*(int *)(param_1 + 0x2c0) +
                                (*(int *)(param_1 + 0x2c0) >> 0x1f & 0xffffU)) >> 0x10)) *
                         *(int *)(param_1 + 0x2c8)) / local_3c;
    }
    else {
      local_38 = 200;
    }
    if (local_38 < 0) {
      local_40 = 0;
    }
    else {
      if (*(int *)(param_1 + 0x2c4) < 1) {
        local_44 = 1;
      }
      else {
        local_44 = *(int *)(param_1 + 0x2c4);
      }
      if (((int)(*(int *)(param_1 + 700) + (*(int *)(param_1 + 700) >> 0x1f & 0xffffU)) >> 0x10) -
          ((((int)(*(int *)(param_1 + 700) + (*(int *)(param_1 + 700) >> 0x1f & 0xffffU)) >> 0x10) -
           ((int)(*(int *)(param_1 + 0x2c0) + (*(int *)(param_1 + 0x2c0) >> 0x1f & 0xffffU)) >> 0x10
           )) * *(int *)(param_1 + 0x2c8)) / local_44 < 0xc9) {
        if (*(int *)(param_1 + 0x2c4) < 1) {
          local_4c = 1;
        }
        else {
          local_4c = *(int *)(param_1 + 0x2c4);
        }
        local_48 = ((int)(*(int *)(param_1 + 700) + (*(int *)(param_1 + 700) >> 0x1f & 0xffffU)) >>
                   0x10) - ((((int)(*(int *)(param_1 + 700) +
                                   (*(int *)(param_1 + 700) >> 0x1f & 0xffffU)) >> 0x10) -
                            ((int)(*(int *)(param_1 + 0x2c0) +
                                  (*(int *)(param_1 + 0x2c0) >> 0x1f & 0xffffU)) >> 0x10)) *
                           *(int *)(param_1 + 0x2c8)) / local_4c;
      }
      else {
        local_48 = 200;
      }
      local_40 = local_48;
    }
    if (*(int *)(param_1 + 0x2c4) < 1) {
      local_50 = 1;
    }
    else {
      local_50 = *(int *)(param_1 + 0x2c4);
    }
    if (((int)(*(uint *)(param_1 + 700) & 0xff00) >> 8) -
        ((((int)(*(uint *)(param_1 + 700) & 0xff00) >> 8) -
         ((int)(*(uint *)(param_1 + 0x2c0) & 0xff00) >> 8)) * *(int *)(param_1 + 0x2c8)) / local_50
        < 0xc9) {
      if (*(int *)(param_1 + 0x2c4) < 1) {
        local_58 = 1;
      }
      else {
        local_58 = *(int *)(param_1 + 0x2c4);
      }
      local_54 = ((int)(*(uint *)(param_1 + 700) & 0xff00) >> 8) -
                 ((((int)(*(uint *)(param_1 + 700) & 0xff00) >> 8) -
                  ((int)(*(uint *)(param_1 + 0x2c0) & 0xff00) >> 8)) * *(int *)(param_1 + 0x2c8)) /
                 local_58;
    }
    else {
      local_54 = 200;
    }
    if (local_54 < 0) {
      local_5c = 0;
    }
    else {
      if (*(int *)(param_1 + 0x2c4) < 1) {
        local_60 = 1;
      }
      else {
        local_60 = *(int *)(param_1 + 0x2c4);
      }
      if (((int)(*(uint *)(param_1 + 700) & 0xff00) >> 8) -
          ((((int)(*(uint *)(param_1 + 700) & 0xff00) >> 8) -
           ((int)(*(uint *)(param_1 + 0x2c0) & 0xff00) >> 8)) * *(int *)(param_1 + 0x2c8)) /
          local_60 < 0xc9) {
        if (*(int *)(param_1 + 0x2c4) < 1) {
          local_68 = 1;
        }
        else {
          local_68 = *(int *)(param_1 + 0x2c4);
        }
        local_64 = ((int)(*(uint *)(param_1 + 700) & 0xff00) >> 8) -
                   ((((int)(*(uint *)(param_1 + 700) & 0xff00) >> 8) -
                    ((int)(*(uint *)(param_1 + 0x2c0) & 0xff00) >> 8)) * *(int *)(param_1 + 0x2c8))
                   / local_68;
      }
      else {
        local_64 = 200;
      }
      local_5c = local_64;
    }
    if (*(int *)(param_1 + 0x2c4) < 1) {
      local_6c = 1;
    }
    else {
      local_6c = *(int *)(param_1 + 0x2c4);
    }
    if ((int)((*(uint *)(param_1 + 700) & 0xff) -
             (int)(((*(uint *)(param_1 + 700) & 0xff) - (*(uint *)(param_1 + 0x2c0) & 0xff)) *
                  *(int *)(param_1 + 0x2c8)) / local_6c) < 0xc9) {
      if (*(int *)(param_1 + 0x2c4) < 1) {
        local_74 = 1;
      }
      else {
        local_74 = *(int *)(param_1 + 0x2c4);
      }
      local_70 = (*(uint *)(param_1 + 700) & 0xff) -
                 (int)(((*(uint *)(param_1 + 700) & 0xff) - (*(uint *)(param_1 + 0x2c0) & 0xff)) *
                      *(int *)(param_1 + 0x2c8)) / local_74;
    }
    else {
      local_70 = 200;
    }
    if (local_70 < 0) {
      local_78 = 0;
    }
    else {
      if (*(int *)(param_1 + 0x2c4) < 1) {
        local_7c = 1;
      }
      else {
        local_7c = *(int *)(param_1 + 0x2c4);
      }
      if ((int)((*(uint *)(param_1 + 700) & 0xff) -
               (int)(((*(uint *)(param_1 + 700) & 0xff) - (*(uint *)(param_1 + 0x2c0) & 0xff)) *
                    *(int *)(param_1 + 0x2c8)) / local_7c) < 0xc9) {
        if (*(int *)(param_1 + 0x2c4) < 1) {
          local_84 = 1;
        }
        else {
          local_84 = *(int *)(param_1 + 0x2c4);
        }
        local_80 = (*(uint *)(param_1 + 700) & 0xff) -
                   (int)(((*(uint *)(param_1 + 700) & 0xff) - (*(uint *)(param_1 + 0x2c0) & 0xff)) *
                        *(int *)(param_1 + 0x2c8)) / local_84;
      }
      else {
        local_80 = 200;
      }
      local_78 = local_80;
    }
    *(int *)(param_1 + 0x2c0) = local_5c * 0x100 + local_40 * 0x10000 + local_78;
    if (param_3 / 2 + 100 < 0xc9) {
      local_88 = param_3 / 2 + 100;
    }
    else {
      local_88 = 200;
    }
    if (local_88 < 0) {
      local_8c = 0;
    }
    else {
      if (param_3 / 2 + 100 < 0xc9) {
        local_90 = param_3 / 2 + 100;
      }
      else {
        local_90 = 200;
      }
      local_8c = local_90;
    }
    if (param_4 / 2 + 100 < 0xc9) {
      local_94 = param_4 / 2 + 100;
    }
    else {
      local_94 = 200;
    }
    if (local_94 < 0) {
      local_98 = 0;
    }
    else {
      if (param_4 / 2 + 100 < 0xc9) {
        local_9c = param_4 / 2 + 100;
      }
      else {
        local_9c = 200;
      }
      local_98 = local_9c;
    }
    if (param_5 / 2 + 100 < 0xc9) {
      local_a0 = param_5 / 2 + 100;
    }
    else {
      local_a0 = 200;
    }
    if (local_a0 < 0) {
      local_a4 = 0;
    }
    else {
      if (param_5 / 2 + 100 < 0xc9) {
        local_a8 = param_5 / 2 + 100;
      }
      else {
        local_a8 = 200;
      }
      local_a4 = local_a8;
    }
    *(int *)(param_1 + 700) = local_98 * 0x100 + local_8c * 0x10000 + local_a4;
    *(int *)(param_1 + 0x2c8) = param_6;
    *(int *)(param_1 + 0x2c4) = param_6;
    break;
  case 2:
    if (*(int *)(param_1 + 0x2dc) < 1) {
      local_ac = 1;
    }
    else {
      local_ac = *(int *)(param_1 + 0x2dc);
    }
    *(int *)(param_1 + 0x2d0) =
         *(int *)(param_1 + 0x2cc) -
         ((*(int *)(param_1 + 0x2cc) - *(int *)(param_1 + 0x2d0)) * *(int *)(param_1 + 0x2e0)) /
         local_ac;
    if (*(int *)(param_1 + 0x2dc) < 1) {
      local_b0 = 1;
    }
    else {
      local_b0 = *(int *)(param_1 + 0x2dc);
    }
    *(int *)(param_1 + 0x2d8) =
         *(int *)(param_1 + 0x2d4) -
         ((*(int *)(param_1 + 0x2d4) - *(int *)(param_1 + 0x2d8)) * *(int *)(param_1 + 0x2e0)) /
         local_b0;
    *(int *)(param_1 + 0x2cc) = param_3;
    *(int *)(param_1 + 0x2d4) = param_4;
    *(int *)(param_1 + 0x2e0) = param_6;
    *(int *)(param_1 + 0x2dc) = param_6;
    break;
  case 3:
    if (param_6 < 1) {
      local_b4 = 1;
    }
    else {
      local_b4 = param_6;
    }
    *(int *)(param_1 + 0x2e4) = param_3;
    *(int *)(param_1 + 0x2e8) = param_4;
    *(int *)(param_1 + 0x2f4) = param_5;
    *(int *)(param_1 + 0x2f8) = local_b4;
    *(int *)(param_1 + 0x2fc) = local_b4 << 1;
    break;
  case 4:
    if (*(int *)(param_1 + 0x318) < 1) {
      local_b8 = 1;
    }
    else {
      local_b8 = *(int *)(param_1 + 0x318);
    }
    *(int *)(param_1 + 0x314) =
         *(int *)(param_1 + 0x310) -
         ((*(int *)(param_1 + 0x310) - *(int *)(param_1 + 0x314)) * *(int *)(param_1 + 0x31c)) /
         local_b8;
    if (*(int *)(param_1 + 0x314) == 100) {
      *(int *)(param_1 + 0x304) = param_3;
      *(int *)(param_1 + 0x30c) = param_4;
    }
    else {
      if (*(int *)(param_1 + 0x318) < 1) {
        local_bc = 1;
      }
      else {
        local_bc = *(int *)(param_1 + 0x318);
      }
      *(int *)(param_1 + 0x304) =
           *(int *)(param_1 + 0x300) -
           ((*(int *)(param_1 + 0x300) - *(int *)(param_1 + 0x304)) * *(int *)(param_1 + 0x31c)) /
           local_bc;
      if (*(int *)(param_1 + 0x318) < 1) {
        local_c0 = 1;
      }
      else {
        local_c0 = *(int *)(param_1 + 0x318);
      }
      *(int *)(param_1 + 0x30c) =
           *(int *)(param_1 + 0x308) -
           ((*(int *)(param_1 + 0x308) - *(int *)(param_1 + 0x30c)) * *(int *)(param_1 + 0x31c)) /
           local_c0;
    }
    *(int *)(param_1 + 0x300) = param_3;
    *(int *)(param_1 + 0x308) = param_4;
    *(int *)(param_1 + 0x310) = param_5;
    *(int *)(param_1 + 0x31c) = param_6;
    *(int *)(param_1 + 0x318) = param_6;
    break;
  case 5:
    if (param_3 / 2 + 100 < 0xc9) {
      local_c4 = param_3 / 2 + 100;
    }
    else {
      local_c4 = 200;
    }
    if (local_c4 < 0) {
      local_c8 = 0;
    }
    else {
      if (param_3 / 2 + 100 < 0xc9) {
        local_cc = param_3 / 2 + 100;
      }
      else {
        local_cc = 200;
      }
      local_c8 = local_cc;
    }
    if (param_4 / 2 + 100 < 0xc9) {
      local_d0 = param_4 / 2 + 100;
    }
    else {
      local_d0 = 200;
    }
    if (local_d0 < 0) {
      local_d4 = 0;
    }
    else {
      if (param_4 / 2 + 100 < 0xc9) {
        local_d8 = param_4 / 2 + 100;
      }
      else {
        local_d8 = 200;
      }
      local_d4 = local_d8;
    }
    if (param_5 / 2 + 100 < 0xc9) {
      local_dc = param_5 / 2 + 100;
    }
    else {
      local_dc = 200;
    }
    if (local_dc < 0) {
      local_e0 = 0;
    }
    else {
      if (param_5 / 2 + 100 < 0xc9) {
        local_e4 = param_5 / 2 + 100;
      }
      else {
        local_e4 = 200;
      }
      local_e0 = local_e4;
    }
    *(int *)(param_1 + 800) = local_d4 * 0x100 + local_c8 * 0x10000 + local_e0;
    *(undefined4 *)(param_1 + 0x328) = 0;
    *(int *)(param_1 + 0x324) = param_6;
    *(undefined4 *)(param_1 + 0x32c) = 0;
    break;
  case 6:
    if (param_3 / 2 + 100 < 0xc9) {
      local_e8 = param_3 / 2 + 100;
    }
    else {
      local_e8 = 200;
    }
    if (local_e8 < 0) {
      local_ec = 0;
    }
    else {
      if (param_3 / 2 + 100 < 0xc9) {
        local_f0 = param_3 / 2 + 100;
      }
      else {
        local_f0 = 200;
      }
      local_ec = local_f0;
    }
    if (param_4 / 2 + 100 < 0xc9) {
      local_f4 = param_4 / 2 + 100;
    }
    else {
      local_f4 = 200;
    }
    if (local_f4 < 0) {
      local_f8 = 0;
    }
    else {
      if (param_4 / 2 + 100 < 0xc9) {
        local_fc = param_4 / 2 + 100;
      }
      else {
        local_fc = 200;
      }
      local_f8 = local_fc;
    }
    if (param_5 / 2 + 100 < 0xc9) {
      local_100 = param_5 / 2 + 100;
    }
    else {
      local_100 = 200;
    }
    if (local_100 < 0) {
      local_104 = 0;
    }
    else {
      if (param_5 / 2 + 100 < 0xc9) {
        local_108 = param_5 / 2 + 100;
      }
      else {
        local_108 = 200;
      }
      local_104 = local_108;
    }
    *(int *)(param_1 + 800) = local_f8 * 0x100 + local_ec * 0x10000 + local_104;
    *(undefined4 *)(param_1 + 0x328) = 0;
    *(int *)(param_1 + 0x324) = param_6;
    *(undefined4 *)(param_1 + 0x32c) = 1;
    break;
  case 7:
    *(int *)(param_1 + 0x330) = param_3;
    *(int *)(param_1 + 0x334) = param_4;
    *(int *)(param_1 + 0x340) = param_5;
    *(int *)(param_1 + 0x33c) = param_6;
    *(int *)(param_1 + 0x338) = param_6 << 1;
    break;
  case 8:
  case 9:
  case 10:
    *(int *)(param_1 + 0x344) = param_3;
    *(int *)(param_1 + 0x348) = param_4;
    *(int *)(param_1 + 0x350) = param_6;
    *(int *)(param_1 + 0x34c) = param_6;
    *(int *)(param_1 + 0x358) = param_3;
    *(int *)(param_1 + 0x354) = param_2 + -8;
  }
  return;
}

