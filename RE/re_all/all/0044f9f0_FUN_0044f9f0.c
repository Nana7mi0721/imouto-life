
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0044f9f0(int param_1)

{
  char cVar1;
  byte bVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_2c;
  uint local_28;
  int local_1c;
  uint local_14;
  uint local_c;
  
  if ((DAT_00a117ae == '\0') && (DAT_00a18ad0 != 1)) {
    local_c = 0;
    cVar1 = *(char *)(param_1 + 0xe);
    if (cVar1 == '\0') {
      local_1c = *(int *)(param_1 + 8);
    }
    else {
      local_1c = *(int *)(param_1 + 8) + -1;
    }
    uVar5 = 2;
    FUN_004cecd0(local_1c);
    puVar3 = (uint *)FUN_004ce990(uVar5);
    if ((*puVar3 & 0xf00) == 0x100) {
      local_c = FUN_00429cb0(0,cVar1,param_1 + 0x854,*(undefined4 *)(param_1 + 0x884));
    }
    uVar5 = 2;
    FUN_004cecd0(local_1c);
    puVar3 = (uint *)FUN_004ce990(uVar5);
    if ((*puVar3 & 0xf00) == 0x200) {
      local_c = FUN_00429e40(0,cVar1,param_1 + 0x858,*(undefined4 *)(param_1 + 0x884));
    }
    uVar5 = 2;
    FUN_004cecd0(local_1c);
    puVar3 = (uint *)FUN_004ce990(uVar5);
    if ((*puVar3 & 0xf00) == 0x300) {
      uVar5 = 2;
      FUN_004cecd0(local_1c);
      puVar3 = (uint *)FUN_004ce990(uVar5);
      switch(*puVar3 & 0xf) {
      case 0:
        if (cVar1 == '\0') {
          if (local_c == 0) {
            uVar5 = 2;
            FUN_004cecd0(local_1c);
            puVar3 = (uint *)FUN_004ce990(uVar5);
            if ((*puVar3 & 0x10) != 0) {
              local_c = -(uint)(DAT_00a1461a != '\0') & 0x14;
            }
          }
          if (local_c == 0) {
            uVar5 = 2;
            FUN_004cecd0(local_1c);
            puVar3 = (uint *)FUN_004ce990(uVar5);
            if ((*puVar3 & 0x20) != 0) {
              local_c = -(uint)(DAT_00a1461b != '\0') & 0x15;
            }
          }
          if (local_c == 0) {
            uVar5 = 2;
            FUN_004cecd0(local_1c);
            puVar3 = (uint *)FUN_004ce990(uVar5);
            if ((*puVar3 & 0x40) != 0) {
              local_c = -(uint)(DAT_00a1461c != '\0') & 0x16;
            }
          }
        }
        else {
          if (local_c == 0) {
            uVar5 = 2;
            FUN_004cecd0(local_1c);
            puVar3 = (uint *)FUN_004ce990(uVar5);
            if ((*puVar3 & 0x10) != 0) {
              local_c = -(uint)(DAT_00a1461d != '\0') & 0x14;
            }
          }
          if (local_c == 0) {
            uVar5 = 2;
            FUN_004cecd0(local_1c);
            puVar3 = (uint *)FUN_004ce990(uVar5);
            if ((*puVar3 & 0x20) != 0) {
              local_c = -(uint)(DAT_00a1461e != '\0') & 0x15;
            }
          }
          if (local_c == 0) {
            uVar5 = 2;
            FUN_004cecd0(local_1c);
            puVar3 = (uint *)FUN_004ce990(uVar5);
            if ((*puVar3 & 0x40) != 0) {
              local_c = -(uint)(DAT_00a1461f != '\0') & 0x16;
            }
          }
        }
        break;
      case 1:
        local_c = DAT_00a14620;
        break;
      case 2:
        local_c = DAT_00a14624;
        break;
      case 3:
        local_c = DAT_00a14640;
      }
    }
    uVar5 = 2;
    FUN_004cecd0(local_1c);
    puVar3 = (uint *)FUN_004ce990(uVar5);
    if ((*puVar3 & 0xf00) == 0) {
      local_14 = 1;
      if (local_c == 0) {
        uVar5 = 2;
        FUN_004cecd0(local_1c);
        puVar3 = (uint *)FUN_004ce990(uVar5);
        if ((*puVar3 & 0x10) != 0) {
          if (cVar1 == '\0') {
            local_2c = (uint)DAT_00a1466c * 10;
          }
          else {
            if (DAT_00a18b2c == 1) {
              if (-(DAT_00a148a0 & 1) == -(uint)(DAT_00a14670 != 0) ||
                  (uint)(DAT_00a14670 != 0) < (DAT_00a148a0 & 1)) {
                local_28 = DAT_00a148a0 & 1;
              }
              else {
                local_28 = (uint)(DAT_00a14670 != 0);
              }
            }
            else {
              local_28 = (uint)DAT_00a14670;
            }
            local_28 = local_28 * 10;
            local_2c = local_28;
          }
          local_c = local_2c;
          local_14 = (uint)((DAT_00a1466c & DAT_00a18b2c) == 0);
        }
      }
      if (local_c == 0) {
        uVar5 = 2;
        FUN_004cecd0(local_1c);
        puVar3 = (uint *)FUN_004ce990(uVar5);
        if ((*puVar3 & 0x20) != 0) {
          if (cVar1 == '\0') {
            local_38 = (uint)DAT_00a1466d * 0xb;
          }
          else {
            if (DAT_00a18b30 == 1) {
              if (-(DAT_00a148a4 & local_14) == -(uint)(DAT_00a14671 != 0) ||
                  (uint)(DAT_00a14671 != 0) < (DAT_00a148a4 & local_14)) {
                local_34 = DAT_00a148a4 & local_14;
              }
              else {
                local_34 = (uint)(DAT_00a14671 != 0);
              }
            }
            else {
              local_34 = (uint)DAT_00a14671;
            }
            local_34 = local_34 * 0xb;
            local_38 = local_34;
          }
          local_c = local_38;
          local_14 = (DAT_00a1466d & DAT_00a18b30) == 0 & local_14;
        }
      }
      if (local_c == 0) {
        uVar5 = 2;
        FUN_004cecd0(local_1c);
        puVar3 = (uint *)FUN_004ce990(uVar5);
        if ((*puVar3 & 0x40) != 0) {
          bVar2 = DAT_00a1466e;
          if (cVar1 != '\0') {
            bVar2 = DAT_00a14672;
          }
          local_3c = (uint)bVar2 * 0xc;
          local_c = local_3c;
        }
      }
      if (local_c == 0) {
        uVar5 = 2;
        FUN_004cecd0(local_1c);
        puVar3 = (uint *)FUN_004ce990(uVar5);
        switch(*puVar3 & 0xf) {
        case 1:
          if (cVar1 == '\0') {
            local_44 = DAT_00a1462c;
          }
          else {
            local_44 = -(uint)(local_14 != 0) & DAT_00a14634;
          }
          local_c = local_44;
          break;
        case 2:
          if (cVar1 == '\0') {
            local_48 = DAT_00a14628;
          }
          else {
            local_48 = -(uint)(local_14 != 0) & _DAT_00a1463c;
          }
          local_c = local_48;
          break;
        case 3:
          if (cVar1 == '\0') {
            local_50 = (uint)DAT_00a14600._3_1_;
          }
          else {
            if ((((DAT_00a14600._3_1_ == 0) || (DAT_00a14634 == 0)) || (local_14 == 0)) &&
               (DAT_00a1460e == '\0')) {
              local_4c = 0;
            }
            else {
              local_4c = 1;
            }
            local_50 = local_4c;
          }
          local_c = local_50 << 3;
          break;
        case 4:
          if (cVar1 == '\0') {
            local_58 = (uint)DAT_00a14604;
          }
          else {
            if ((((DAT_00a14604 == 0) || (DAT_00a14634 == 0)) || (local_14 == 0)) &&
               (DAT_00a1460f == '\0')) {
              local_54 = 0;
            }
            else {
              local_54 = 1;
            }
            local_58 = local_54;
          }
          local_c = local_58 << 1;
          break;
        case 5:
          if (cVar1 == '\0') {
            local_60 = (uint)DAT_00a14605;
          }
          else {
            if ((((DAT_00a14605 == 0) || (DAT_00a14634 == 0)) || (local_14 == 0)) &&
               (DAT_00a14610 == '\0')) {
              local_5c = 0;
            }
            else {
              local_5c = 1;
            }
            local_60 = local_5c;
          }
          local_c = local_60 << 2;
          break;
        case 6:
          if (cVar1 == '\0') {
            local_68 = (uint)DAT_00a14606;
          }
          else {
            if ((((DAT_00a14606 == 0) || (DAT_00a14634 == 0)) || (local_14 == 0)) &&
               (DAT_00a14611 == '\0')) {
              local_64 = 0;
            }
            else {
              local_64 = 1;
            }
            local_68 = local_64;
          }
          local_c = local_68 * 6;
          break;
        case 7:
          if (cVar1 == '\0') {
            local_6c = DAT_00a1464c;
          }
          else {
            local_6c = -(uint)(local_14 != 0) & _DAT_00a14654;
          }
          local_c = local_6c;
          break;
        case 8:
          if (cVar1 == '\0') {
            local_70 = DAT_00a14658;
          }
          else {
            local_70 = -(uint)(local_14 != 0) & _DAT_00a14660;
          }
          local_c = local_70;
        }
      }
    }
    if ((cVar1 == '\0') || (local_c == 0)) {
      if (cVar1 == '\0') {
        uVar5 = 1;
        FUN_004cecd0(local_1c);
        puVar4 = (undefined4 *)FUN_004ce990(uVar5);
        FUN_00486e50(*puVar4,local_c);
      }
    }
    else {
      uVar5 = 1;
      FUN_004cecd0(local_1c);
      puVar4 = (undefined4 *)FUN_004ce990(uVar5);
      FUN_00486e50(*puVar4,local_c);
      *(undefined1 *)(param_1 + 0xe) = 0;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return;
}

