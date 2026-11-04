
undefined4 FUN_005846f0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
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
  undefined1 local_60 [12];
  undefined1 local_54 [12];
  undefined1 local_48 [12];
  undefined1 local_3c [12];
  undefined1 local_30 [12];
  undefined1 local_24 [12];
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  if (DAT_00dccde0 == '\0') {
    return 0xffffffff;
  }
  iVar4 = *(int *)(param_1 + 0x40);
  iVar2 = 0;
  local_64 = iVar4;
  if (0 < *(int *)(iVar4 + 0xa0)) {
    iVar3 = 0;
    do {
      iVar1 = *(int *)(param_1 + 0x1bc) + iVar3;
      if (((*(int *)(iVar1 + 0x44) != 0) &&
          (iVar1 = FUN_00519300(*(undefined4 *)(iVar1 + 0x48),0), iVar1 != 0)) &&
         (*(int *)(iVar1 + 0x34) != -1)) {
        FUN_0057b670(*(int *)(iVar1 + 0x34),0);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x74;
    } while (iVar2 < *(int *)(iVar4 + 0xa0));
  }
  iVar4 = *(int *)(*(int *)(param_1 + 0x40) + 0xac);
  if (DAT_00dda454 < iVar4) {
    if (DAT_00dda450 != 0) {
      FUN_0056e1d0(DAT_00dda450);
    }
    DAT_00dda450 = FUN_0056e030(iVar4 * 0xc,"..\\..\\..\\..\\Source\\Library\\Main\\DxModel.cpp",
                                0x1c9);
    if (DAT_00dda450 == 0) {
      return 0xffffffff;
    }
    DAT_00dda454 = iVar4;
  }
  iVar4 = DAT_00dda450;
  local_78 = *(int *)(*(int *)(param_1 + 0x40) + 0xac) * 4;
  local_68 = local_78 + DAT_00dda450;
  local_78 = local_78 + local_68;
  local_98 = 0;
  local_84 = 0;
  local_80 = 0;
  local_88 = DAT_00dda450;
  if (*(int *)(*(int *)(param_1 + 0x40) + 0xf0) != 0) {
    FUN_005db6f0(*(undefined4 *)(param_1 + 4));
  }
  FUN_005db710(param_1);
  local_7c = *(int *)(param_1 + 0x17c);
  local_6c = 0;
  iVar2 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 0x40) + 0x7c)) {
    local_70 = local_7c + 0x100;
    do {
      iVar4 = local_70;
      if (*(int *)(*(int *)(local_70 + -0xf0) + 0x170) != 0) {
        if ((**(uint **)(local_70 + 0x11c) & *(uint *)(*(int *)(local_70 + 0x118) + 0xc)) != 0) {
          FUN_005833e0(0);
        }
        iVar2 = DAT_00a380c4;
        if (*(char *)(iVar4 + 0x168) != '\0') {
          if (((*(int *)(local_64 + 0x44) == 0) && (DAT_00a3810c == 0)) &&
             (iVar3 = *(int *)(iVar4 + -0xf0), *(int *)(iVar3 + 0x164) == 0)) {
            local_94 = *(undefined4 *)(iVar3 + 0x144);
            local_90 = *(undefined4 *)(iVar3 + 0x148);
            local_8c = *(undefined4 *)(iVar3 + 0x14c);
            if (DAT_00a380c4 == 0) {
              FUN_005826d0(local_60,&local_94,iVar4);
            }
            else {
              FUN_00582730(local_60,&local_94);
            }
            local_94 = *(undefined4 *)(*(int *)(iVar4 + -0xf0) + 0x150);
            if (iVar2 == 0) {
              FUN_005826d0(local_54,&local_94,iVar4);
            }
            else {
              FUN_00582730(local_54,&local_94);
            }
            local_90 = *(undefined4 *)(*(int *)(iVar4 + -0xf0) + 0x154);
            if (iVar2 == 0) {
              FUN_005826d0(local_48,&local_94,iVar4);
            }
            else {
              FUN_00582730(local_48,&local_94);
            }
            local_94 = *(undefined4 *)(*(int *)(iVar4 + -0xf0) + 0x144);
            if (iVar2 == 0) {
              FUN_005826d0(local_3c,&local_94,iVar4);
            }
            else {
              FUN_00582730(local_3c,&local_94);
            }
            local_8c = *(undefined4 *)(*(int *)(iVar4 + -0xf0) + 0x158);
            if (iVar2 == 0) {
              FUN_005826d0(local_30,&local_94,iVar4);
            }
            else {
              FUN_00582730(local_30,&local_94);
            }
            local_90 = *(undefined4 *)(*(int *)(iVar4 + -0xf0) + 0x148);
            if (iVar2 == 0) {
              FUN_005826d0(local_24,&local_94,iVar4);
            }
            else {
              FUN_00582730(local_24,&local_94);
            }
            local_94 = *(undefined4 *)(*(int *)(iVar4 + -0xf0) + 0x150);
            if (iVar2 == 0) {
              FUN_005826d0(local_18,&local_94,iVar4);
            }
            else {
              FUN_00582730(local_18,&local_94);
            }
            local_90 = *(undefined4 *)(*(int *)(iVar4 + -0xf0) + 0x154);
            if (iVar2 == 0) {
              FUN_005826d0(local_c,&local_94,iVar4);
            }
            else {
              FUN_00582730(local_c,&local_94);
            }
            iVar2 = FUN_0051bd00(local_60);
            if (iVar2 == 1) goto LAB_00584c8d;
          }
          if (*(int *)(*(int *)(param_1 + 0x40) + 0x58) == 0) {
            iVar2 = *(int *)(iVar4 + 0x108);
            iVar3 = 0;
            if (0 < *(int *)(*(int *)(iVar4 + -0xf0) + 0x170)) {
              do {
                if ((**(uint **)(iVar2 + 0x10) & *(uint *)(*(int *)(iVar2 + 0xc) + 0xc)) != 0) {
                  FUN_005833e0(iVar2);
                }
                if (*(char *)(iVar2 + 0x5c) != '\0') {
                  if (*(char *)(iVar2 + 0xa4) == '\0') {
                    FUN_00584470(*(undefined4 *)(param_1 + 4),
                                 (iVar2 - *(int *)(param_1 + 0x1b0)) / 0xb8);
                  }
                  if (*(char *)(iVar2 + 0xa5) == '\0') {
                    *(int *)(local_88 + local_98 * 4) = iVar2;
                    local_98 = local_98 + 1;
                  }
                  else if (*(char *)(*(int *)(iVar2 + 4) + 0x4b) == '\0') {
                    *(int *)(local_68 + local_84 * 4) = iVar2;
                    local_84 = local_84 + 1;
                  }
                  else {
                    *(int *)(local_78 + local_80 * 4) = iVar2;
                    local_80 = local_80 + 1;
                  }
                }
                iVar3 = iVar3 + 1;
                iVar2 = iVar2 + 0xb8;
              } while (iVar3 < *(int *)(*(int *)(iVar4 + -0xf0) + 0x170));
            }
          }
          else {
            iVar2 = *(int *)(iVar4 + 0x108);
            local_74 = 0;
            if (0 < *(int *)(*(int *)(iVar4 + -0xf0) + 0x170)) {
              do {
                if ((**(uint **)(iVar2 + 0x10) & *(uint *)(*(int *)(iVar2 + 0xc) + 0xc)) != 0) {
                  FUN_005833e0(iVar2);
                }
                if (*(char *)(iVar2 + 0x5c) != '\0') {
                  iVar4 = *(int *)(*(int *)(param_1 + 0x40) + 0x9c);
                  iVar1 = 0;
                  iVar3 = local_98;
                  if (0 < local_98) {
                    do {
                      if ((**(int **)(iVar2 + 8) - iVar4) / 0x240 <
                          (**(int **)(*(int *)(local_88 + iVar1 * 4) + 8) - iVar4) / 0x240) break;
                      iVar1 = iVar1 + 1;
                    } while (iVar1 < local_98);
                  }
                  while (iVar3 = iVar3 + -1, iVar1 <= iVar3) {
                    *(undefined4 *)(local_88 + 4 + iVar3 * 4) =
                         *(undefined4 *)(local_88 + iVar3 * 4);
                  }
                  local_98 = local_98 + 1;
                  *(int *)(local_88 + iVar1 * 4) = iVar2;
                  iVar4 = local_70;
                }
                local_74 = local_74 + 1;
                iVar2 = iVar2 + 0xb8;
              } while (local_74 < *(int *)(*(int *)(iVar4 + -0xf0) + 0x170));
            }
          }
        }
      }
LAB_00584c8d:
      local_6c = local_6c + 1;
      local_7c = local_7c + 0x2b8;
      local_70 = iVar4 + 0x2b8;
    } while (local_6c < *(int *)(*(int *)(param_1 + 0x40) + 0x7c));
    iVar2 = local_98;
    iVar4 = local_88;
  }
  if (((DAT_00dccde8 == 0) || (DAT_00dccde8 == 2)) && (iVar3 = 0, 0 < iVar2)) {
    do {
      FUN_005db750(*(undefined4 *)(iVar4 + iVar3 * 4),0xffffffff);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  iVar2 = local_68;
  iVar4 = local_84;
  if ((DAT_00dccde8 == 0) || (DAT_00dccde8 == 1)) {
    iVar3 = 0;
    if (0 < local_84) {
      do {
        FUN_005db750(*(undefined4 *)(iVar2 + iVar3 * 4),0xffffffff);
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar4);
    }
    iVar2 = local_78;
    iVar4 = local_80;
    iVar3 = 0;
    if (0 < local_80) {
      do {
        FUN_005db750(*(undefined4 *)(iVar2 + iVar3 * 4),0xffffffff);
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar4);
    }
  }
  FUN_005db730();
  *(undefined4 *)(param_1 + 400) = 0;
  return 0;
}

