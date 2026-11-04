
undefined4 FUN_0044a350(uint param_1,uint param_2,int param_3,undefined4 param_4,int param_5)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  int local_20;
  int local_1c;
  int local_18;
  
  uVar4 = param_2 + 1;
  cVar3 = FUN_0047eb30(param_1,uVar4);
  if (cVar3 == '\0') {
    uVar5 = 0;
  }
  else {
    bVar1 = false;
    bVar2 = false;
    for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
      for (local_1c = 2; -1 < local_1c; local_1c = local_1c + -1) {
        uVar7 = param_1 + local_18;
        local_20 = FUN_0047a4d0(uVar7,uVar4,local_1c);
        while ((local_20 == 0 && (0 < local_1c))) {
          local_1c = local_1c + -1;
          local_20 = FUN_0047a4d0(uVar7,uVar4,local_1c);
        }
        if (local_20 == -1) {
          return 0;
        }
        puVar6 = (uint *)FUN_004ce990(local_20);
        if ((*puVar6 & 0x20) == 0) {
          if (((param_3 == 6) && (local_18 == 0)) &&
             (puVar6 = (uint *)FUN_004ce990(local_20), (*puVar6 & 4) != 0)) {
            uVar7 = param_1 & 0x80000001;
            if ((int)uVar7 < 0) {
              uVar7 = (uVar7 - 1 | 0xfffffffe) + 1;
            }
            if (uVar7 == 1) {
              return 0;
            }
          }
          if (((param_3 == 4) && (local_18 == 1)) &&
             (puVar6 = (uint *)FUN_004ce990(local_20), (*puVar6 & 2) != 0)) {
            uVar7 = param_1 & 0x80000001;
            if ((int)uVar7 < 0) {
              uVar7 = (uVar7 - 1 | 0xfffffffe) + 1;
            }
            if (uVar7 == 1) {
              return 0;
            }
          }
          puVar6 = (uint *)FUN_004ce990(local_20);
          if ((((uint)((byte)(1 << ((char)(param_3 / 2) - 1U & 0x1f)) & 0xf) & *puVar6) != 0) &&
             (param_5 == 1)) {
            if ((param_3 == 6) &&
               ((local_18 == 0 && (puVar6 = (uint *)FUN_004ce990(local_20), (*puVar6 & 4) != 0)))) {
              uVar7 = param_1 & 0x80000001;
              if ((int)uVar7 < 0) {
                uVar7 = (uVar7 - 1 | 0xfffffffe) + 1;
              }
              if (uVar7 == 0) {
                return 0;
              }
            }
            if (((param_3 == 4) && (local_18 == 0)) &&
               (puVar6 = (uint *)FUN_004ce990(local_20), (*puVar6 & 2) != 0)) {
              uVar7 = param_1 & 0x80000001;
              if ((int)uVar7 < 0) {
                uVar7 = (uVar7 - 1 | 0xfffffffe) + 1;
              }
              if (uVar7 == 0) {
                return 0;
              }
            }
            if (param_3 == 2) {
              uVar7 = param_2 & 0x80000001;
              if ((int)uVar7 < 0) {
                uVar7 = (uVar7 - 1 | 0xfffffffe) + 1;
              }
              if ((uVar7 == 0) && (puVar6 = (uint *)FUN_004ce990(local_20), (*puVar6 & 1) != 0)) {
                return 0;
              }
            }
            if (param_3 == 8) {
              uVar7 = param_2 & 0x80000001;
              if ((int)uVar7 < 0) {
                uVar7 = (uVar7 - 1 | 0xfffffffe) + 1;
              }
              if ((uVar7 == 1) && (puVar6 = (uint *)FUN_004ce990(local_20), (*puVar6 & 8) != 0)) {
                return 0;
              }
            }
          }
          if ((param_5 == 2) &&
             (((((param_3 == 2 && (puVar6 = (uint *)FUN_004ce990(local_20), (*puVar6 & 1) != 0)) ||
                ((param_3 == 8 && (puVar6 = (uint *)FUN_004ce990(local_20), (*puVar6 & 8) != 0))))
               || ((param_3 == 4 && (puVar6 = (uint *)FUN_004ce990(local_20), (*puVar6 & 2) != 0))))
              || ((param_3 == 6 && (puVar6 = (uint *)FUN_004ce990(local_20), (*puVar6 & 4) != 0)))))
             ) {
            return 0;
          }
          puVar6 = (uint *)FUN_004ce990(local_20);
          if ((*puVar6 & 0xf) == 0xf) {
            return 0;
          }
          puVar6 = (uint *)FUN_004ce990(local_20);
          if ((*puVar6 & 0x200) == 0) {
            if (local_18 == 0) {
              bVar1 = true;
            }
            else {
              bVar2 = true;
            }
            break;
          }
        }
        else {
          if ((param_5 == 2) && (puVar6 = (uint *)FUN_004ce990(local_20), (*puVar6 & 0xf) != 0)) {
            return 0;
          }
          uVar8 = uVar7 & 0x80000001;
          if ((int)uVar8 < 0) {
            uVar8 = (uVar8 - 1 | 0xfffffffe) + 1;
          }
          if (uVar8 == 0) {
            uVar8 = uVar4 & 0x80000001;
            if ((int)uVar8 < 0) {
              uVar8 = (uVar8 - 1 | 0xfffffffe) + 1;
            }
            if ((uVar8 == 1) && (puVar6 = (uint *)FUN_004ce990(local_20), (*puVar6 & 2) != 0)) {
              return 0;
            }
          }
          uVar8 = uVar7 & 0x80000001;
          if ((int)uVar8 < 0) {
            uVar8 = (uVar8 - 1 | 0xfffffffe) + 1;
          }
          if (uVar8 == 1) {
            uVar8 = uVar4 & 0x80000001;
            if ((int)uVar8 < 0) {
              uVar8 = (uVar8 - 1 | 0xfffffffe) + 1;
            }
            if ((uVar8 == 0) && (puVar6 = (uint *)FUN_004ce990(local_20), (*puVar6 & 4) != 0)) {
              return 0;
            }
          }
          uVar8 = uVar7 & 0x80000001;
          if ((int)uVar8 < 0) {
            uVar8 = (uVar8 - 1 | 0xfffffffe) + 1;
          }
          if (uVar8 == 0) {
            uVar8 = uVar4 & 0x80000001;
            if ((int)uVar8 < 0) {
              uVar8 = (uVar8 - 1 | 0xfffffffe) + 1;
            }
            if ((uVar8 == 0) && (puVar6 = (uint *)FUN_004ce990(local_20), (*puVar6 & 8) != 0)) {
              return 0;
            }
          }
          uVar7 = uVar7 & 0x80000001;
          if ((int)uVar7 < 0) {
            uVar7 = (uVar7 - 1 | 0xfffffffe) + 1;
          }
          if (uVar7 == 1) {
            uVar7 = uVar4 & 0x80000001;
            if ((int)uVar7 < 0) {
              uVar7 = (uVar7 - 1 | 0xfffffffe) + 1;
            }
            if ((uVar7 == 1) && (puVar6 = (uint *)FUN_004ce990(local_20), (*puVar6 & 1) != 0)) {
              return 0;
            }
          }
          puVar6 = (uint *)FUN_004ce990(local_20);
          if ((*puVar6 & 0x200) == 0) {
            if (local_18 == 0) {
              bVar1 = true;
            }
            else {
              bVar2 = true;
            }
            break;
          }
        }
      }
      if ((local_18 == 1) && ((bVar1 || (bVar2)))) {
        return 1;
      }
    }
    uVar5 = 1;
  }
  return uVar5;
}

