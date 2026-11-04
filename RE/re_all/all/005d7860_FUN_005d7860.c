
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005d7860(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined **ppuVar10;
  uint local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint *local_c;
  int local_8;
  
  FUN_0056da60(param_1 + 0x74,"..\\..\\..\\..\\Source\\Library\\Main\\DxHeap.cpp",0x9d6);
  for (piVar1 = *(int **)(param_1 + 0x5c); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0xd]) {
    if (*piVar1 != 0x4d454d44) {
      FUN_0056bca0(&PTR_PTR_00801418);
      _DAT_00000000 = 0xffffffff;
    }
    iVar2 = piVar1[0x11];
    if (*(int *)(param_1 + 0x2c) == 0) {
      if ((piVar1 < *(int **)(iVar2 + 0x10)) ||
         ((int *)(*(int *)(iVar2 + 0x14) + *(int *)(iVar2 + 0x10)) <= piVar1)) {
        FUN_0056bca0(&PTR_PTR_008012d8);
        piVar3 = piVar1;
        if (*(int *)(param_1 + 0x2c) == 0) {
          piVar3 = (int *)piVar1[10];
        }
        FUN_005d7680(piVar3,*(int *)(param_1 + 0x2c));
        _DAT_00000000 = 0xffffffff;
      }
      if (((((piVar1[0x12] != -0x55555556) || (piVar1[0x13] != -0x55555556)) ||
           (piVar1[0x14] != -0x55555556)) ||
          ((piVar1[0x15] != -0x55555556 ||
           (iVar2 = piVar1[8], *(int *)(iVar2 + -0x10 + (int)piVar1) != -0x55555556)))) ||
         ((*(int *)((int)piVar1 + iVar2 + -0xc) != -0x55555556 ||
          ((*(int *)((int)piVar1 + iVar2 + -8) != -0x55555556 ||
           (*(int *)((int)piVar1 + iVar2 + -4) != -0x55555556)))))) {
        ppuVar10 = &PTR_PTR_00801250;
        goto LAB_005d794b;
      }
    }
    else if (((uint)piVar1[9] < *(uint *)(iVar2 + 0x10)) ||
            ((uint)(*(int *)(iVar2 + 0x14) + *(int *)(iVar2 + 0x10)) <= (uint)piVar1[9])) {
      ppuVar10 = &PTR_PTR_00801378;
LAB_005d794b:
      FUN_0056bca0(ppuVar10);
      piVar3 = piVar1;
      if (*(int *)(param_1 + 0x2c) == 0) {
        piVar3 = (int *)piVar1[10];
      }
      FUN_005d7680(piVar3,*(int *)(param_1 + 0x2c));
      _DAT_00000000 = 0xffffffff;
    }
  }
  if (*(int *)(param_1 + 0x2c) == 0) {
    for (uVar5 = *(uint *)(param_1 + 0x5c); uVar5 != 0; uVar5 = *(uint *)(uVar5 + 0x34)) {
      if ((uVar5 & 0xf) != 0) {
        FUN_0056bca0(&PTR_PTR_00801130);
        uVar7 = uVar5;
        if (*(int *)(param_1 + 0x2c) == 0) {
          uVar7 = *(uint *)(uVar5 + 0x28);
        }
        FUN_005d7680(uVar7,*(int *)(param_1 + 0x2c));
        _DAT_00000000 = 0xffffffff;
      }
    }
  }
  else {
    for (iVar2 = *(int *)(param_1 + 0x5c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x34)) {
      if ((*(byte *)(iVar2 + 0x24) & 0xf) != 0) {
        FUN_0056bca0(&PTR_PTR_008011c0);
        iVar6 = iVar2;
        if (*(int *)(param_1 + 0x2c) == 0) {
          iVar6 = *(int *)(iVar2 + 0x28);
        }
        FUN_005d7680(iVar6,*(int *)(param_1 + 0x2c));
        _DAT_00000000 = 0xffffffff;
      }
    }
  }
  iVar6 = 0;
  for (iVar2 = *(int *)(param_1 + 0x5c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x34)) {
    iVar6 = iVar6 + *(int *)(iVar2 + 0x20);
  }
  iVar8 = 0;
  for (iVar2 = *(int *)(param_1 + 0x50); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x24)) {
    iVar8 = iVar8 + *(int *)(iVar2 + 0x14);
  }
  iVar2 = *(int *)(param_1 + 0x68) + *(int *)(param_1 + 0x58);
  if (iVar6 != iVar2) {
    FUN_0056bca0(&PTR_PTR_00801058,iVar6,0,iVar2,0);
    _DAT_00000000 = 0xffffffff;
  }
  if (iVar6 != iVar8) {
    FUN_0056bca0(&PTR_PTR_00800fc8,iVar6,0,iVar8,0);
    _DAT_00000000 = 0xffffffff;
  }
  iVar2 = *(int *)(param_1 + 0x5c);
  if (*(int *)(param_1 + 0x2c) == 0) {
    for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x34)) {
      if (((*(byte *)(iVar2 + 0x16) & 0x10) != 0) &&
         (iVar6 = *(int *)(iVar2 + 0x30), *(int *)(iVar6 + 0x20) + iVar6 != iVar2)) {
        iVar6 = iVar6 + *(int *)(iVar6 + 0x20) * 0x48;
        FUN_0056bca0(&PTR_PTR_00800ce0,iVar6,iVar6 >> 0x1f,iVar2,iVar2 >> 0x1f);
        iVar6 = iVar2;
        if (*(int *)(param_1 + 0x2c) == 0) {
          iVar6 = *(int *)(iVar2 + 0x28);
        }
        FUN_005d7680(iVar6,*(int *)(param_1 + 0x2c));
        _DAT_00000000 = 0xffffffff;
      }
      if ((*(byte *)(iVar2 + 0x16) & 8) != 0) {
        iVar6 = *(int *)(iVar2 + 0x34);
        if (iVar6 != *(int *)(iVar2 + 0x20) + iVar2) {
          iVar8 = iVar2 + *(int *)(iVar2 + 0x20) * 0x48;
          FUN_0056bca0(&PTR_PTR_00800c18,iVar6,iVar6 >> 0x1f,iVar8,iVar8 >> 0x1f);
          iVar6 = iVar2;
          if (*(int *)(param_1 + 0x2c) == 0) {
            iVar6 = *(int *)(iVar2 + 0x28);
          }
          FUN_005d7680(iVar6,*(int *)(param_1 + 0x2c));
          _DAT_00000000 = 0xffffffff;
        }
      }
    }
  }
  else {
    for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x34)) {
      if ((*(byte *)(iVar2 + 0x16) & 0x10) != 0) {
        iVar6 = *(int *)(iVar2 + 0x30);
        iVar8 = *(int *)(iVar2 + 0x24);
        if (*(int *)(iVar6 + 0x24) + *(int *)(iVar6 + 0x20) != iVar8) {
          FUN_0056bca0(&PTR_PTR_00800eb8,*(int *)(iVar6 + 0x24) + *(int *)(iVar6 + 0x20),0,iVar8,
                       iVar8 >> 0x1f);
          iVar6 = iVar2;
          if (*(int *)(param_1 + 0x2c) == 0) {
            iVar6 = *(int *)(iVar2 + 0x28);
          }
          FUN_005d7680(iVar6,*(int *)(param_1 + 0x2c));
          _DAT_00000000 = 0xffffffff;
        }
      }
      if ((*(byte *)(iVar2 + 0x16) & 8) != 0) {
        iVar6 = *(int *)(*(int *)(iVar2 + 0x34) + 0x24);
        iVar8 = *(int *)(iVar2 + 0x24) + *(int *)(iVar2 + 0x20);
        if (iVar6 != iVar8) {
          FUN_0056bca0(&PTR_PTR_00800db8,iVar6,iVar6 >> 0x1f,iVar8,0);
          _DAT_00000000 = 0xffffffff;
        }
      }
    }
  }
  for (iVar2 = *(int *)(param_1 + 0x5c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x34)) {
    if ((*(byte *)(iVar2 + 0x16) & 4) == 0) {
      if (((*(byte *)(iVar2 + 0x16) & 0x10) != 0) &&
         ((*(byte *)(*(int *)(iVar2 + 0x30) + 0x16) & 4) == 0)) {
        FUN_0056bca0(&PTR_PTR_00800bb0);
        iVar6 = iVar2;
        if (*(int *)(param_1 + 0x2c) == 0) {
          iVar6 = *(int *)(iVar2 + 0x28);
        }
        FUN_005d7680(iVar6,*(int *)(param_1 + 0x2c));
        _DAT_00000000 = 0xffffffff;
      }
      if (((*(byte *)(iVar2 + 0x16) & 8) != 0) &&
         ((*(byte *)(*(int *)(iVar2 + 0x34) + 0x16) & 4) == 0)) {
        FUN_0056bca0(&PTR_PTR_00800b48);
        iVar6 = iVar2;
        if (*(int *)(param_1 + 0x2c) == 0) {
          iVar6 = *(int *)(iVar2 + 0x28);
        }
        FUN_005d7680(iVar6,*(int *)(param_1 + 0x2c));
        _DAT_00000000 = 0xffffffff;
      }
    }
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    iVar6 = 0;
    for (iVar2 = *(int *)(param_1 + 0x3c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x3c)) {
      iVar6 = iVar6 + 1;
    }
    iVar2 = *(int *)(param_1 + 0x30) - *(int *)(param_1 + 0x34);
    if (iVar6 != iVar2) {
      FUN_0056bca0(&PTR_PTR_00800a58,iVar6,iVar2);
      _DAT_00000000 = 0xffffffff;
    }
    iVar6 = 0;
    for (iVar2 = *(int *)(param_1 + 0x4c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x24)) {
      iVar6 = iVar6 + 1;
    }
    iVar2 = *(int *)(param_1 + 0x40) - *(int *)(param_1 + 0x44);
    if (iVar6 != iVar2) {
      FUN_0056bca0(&PTR_PTR_00800948,iVar6,iVar2);
      _DAT_00000000 = 0xffffffff;
    }
  }
  iVar2 = *(int *)(param_1 + 0x6c);
  iVar8 = 0;
  iVar6 = 0;
  if (iVar2 != 0) {
    iVar8 = 0;
    do {
      if ((*(byte *)(iVar2 + 0x16) & 4) == 0) {
        FUN_0056bca0(&PTR_PTR_008008e0);
        iVar4 = iVar2;
        if (*(int *)(param_1 + 0x2c) == 0) {
          iVar4 = *(int *)(iVar2 + 0x28);
        }
        FUN_005d7680(iVar4,*(int *)(param_1 + 0x2c));
        _DAT_00000000 = 0xffffffff;
      }
      iVar8 = iVar8 + *(int *)(iVar2 + 0x20);
      iVar2 = *(int *)(iVar2 + 0x3c);
      iVar6 = iVar6 + 1;
    } while (iVar2 != 0);
  }
  if (iVar6 != *(int *)(param_1 + 100)) {
    FUN_0056bca0(&PTR_PTR_00800850,iVar6,*(int *)(param_1 + 100));
    _DAT_00000000 = 0xffffffff;
  }
  if (iVar8 != *(int *)(param_1 + 0x68)) {
    FUN_0056bca0(&PTR_PTR_008007a8,iVar8,*(int *)(param_1 + 0x68));
    _DAT_00000000 = 0xffffffff;
  }
  local_14 = 0;
  local_18 = 0;
  if (*(int *)(param_1 + 0x1c) == 0) {
    iVar2 = *(int *)(param_1 + 0x2318);
    if (iVar2 != 0) {
      local_14 = 0;
      local_18 = 0;
      do {
        if ((*(byte *)(iVar2 + 0x16) & 4) != 0) {
          FUN_0056bca0(&PTR_PTR_00800740);
          iVar6 = iVar2;
          if (*(int *)(param_1 + 0x2c) == 0) {
            iVar6 = *(int *)(iVar2 + 0x28);
          }
          FUN_005d7680(iVar6,*(int *)(param_1 + 0x2c));
          _DAT_00000000 = 0xffffffff;
        }
        local_14 = local_14 + *(int *)(iVar2 + 0x20);
        iVar2 = *(int *)(iVar2 + 0x3c);
        local_18 = local_18 + 1;
      } while (iVar2 != 0);
    }
  }
  else if (*(int *)(param_1 + 0x1c) == 1) {
    local_c = (uint *)(param_1 + 0x298);
    local_1c = 0;
    local_8 = 0xc6;
    do {
      if ((*(uint *)(param_1 + 0x294) & 1 << ((byte)local_1c & 0x1f)) != 0) {
        uVar5 = 0;
        local_10 = 0;
        do {
          if ((*local_c & 1 << ((byte)uVar5 & 0x1f)) != 0) {
            local_10 = local_10 + 1;
            if (*(int *)(param_1 + (local_8 + uVar5) * 4) == 0) {
              FUN_0056bca0(&PTR_PTR_008006e0);
              _DAT_00000000 = 0xffffffff;
            }
            iVar2 = *(int *)(param_1 + (local_8 + uVar5) * 4);
            if (iVar2 != 0) {
              do {
                uVar7 = *(uint *)(iVar2 + 0x20);
                if (uVar7 == 0) {
                  uVar9 = 0xffffffff;
                }
                else {
                  uVar9 = uVar7 | uVar7 >> 1;
                  uVar9 = uVar9 | uVar9 >> 2;
                  uVar9 = uVar9 | uVar9 >> 4;
                  uVar9 = uVar9 | uVar9 >> 8;
                  uVar9 = uVar9 >> 0x10 | uVar9;
                  uVar9 = (uVar9 >> 1 & 0x55555555) + (uVar9 & 0x55555555);
                  uVar9 = (uVar9 >> 2 & 0x33333333) + (uVar9 & 0x33333333);
                  uVar9 = (uVar9 >> 4 & 0xf0f0f0f) + (uVar9 & 0xf0f0f0f);
                  uVar9 = (uVar9 >> 8 & 0xff00ff) + (uVar9 & 0xff00ff);
                  uVar9 = ((uVar9 >> 0x10) - 1) + (uVar9 & 0xffff);
                }
                uVar7 = ((1 << ((byte)uVar9 & 0x1f)) - 1U & uVar7) >> ((byte)uVar9 - 5 & 0x1f);
                if ((uVar9 != local_1c) || (uVar7 != uVar5)) {
                  FUN_0056bca0(&PTR_PTR_00800648,uVar9,local_1c,uVar7,uVar5);
                  _DAT_00000000 = 0xffffffff;
                }
                if ((*(byte *)(iVar2 + 0x17) != uVar9) || (*(byte *)(iVar2 + 0x18) != uVar7)) {
                  FUN_0056bca0(&PTR_PTR_00800580,(uint)*(byte *)(iVar2 + 0x17),uVar9,
                               *(undefined1 *)(iVar2 + 0x18),uVar7);
                  _DAT_00000000 = 0xffffffff;
                }
                if ((*(byte *)(iVar2 + 0x16) & 4) != 0) {
                  FUN_0056bca0(&PTR_PTR_00800508);
                  iVar6 = iVar2;
                  if (*(int *)(param_1 + 0x2c) == 0) {
                    iVar6 = *(int *)(iVar2 + 0x28);
                  }
                  FUN_005d7680(iVar6,*(int *)(param_1 + 0x2c));
                  _DAT_00000000 = 0xffffffff;
                }
                piVar1 = (int *)(iVar2 + 0x20);
                iVar2 = *(int *)(iVar2 + 0x3c);
                local_14 = local_14 + *piVar1;
                local_18 = local_18 + 1;
              } while (iVar2 != 0);
            }
          }
          uVar5 = uVar5 + 1;
        } while ((int)uVar5 < 0x20);
        if (local_10 == 0) {
          FUN_0056bca0(&PTR_PTR_008004a8);
          _DAT_00000000 = 0xffffffff;
        }
      }
      local_1c = local_1c + 1;
      local_c = local_c + 1;
      local_8 = local_8 + 0x20;
    } while (local_8 < 0x4c6);
  }
  if (local_18 != *(int *)(param_1 + 0x54)) {
    FUN_0056bca0(&PTR_PTR_00800410,local_18,*(int *)(param_1 + 0x54));
    _DAT_00000000 = 0xffffffff;
  }
  if (local_14 != *(int *)(param_1 + 0x58)) {
    FUN_0056bca0(&PTR_PTR_00800360,local_14,*(int *)(param_1 + 0x58));
    _DAT_00000000 = 0xffffffff;
  }
  iVar2 = *(int *)(param_1 + 0x6c);
  do {
    if (iVar2 == 0) {
      FUN_0056dac0(param_1 + 0x74);
      return 0;
    }
    uVar5 = *(uint *)(iVar2 + 0x28);
    if (uVar5 % *(uint *)(param_1 + 0x20) != 0) {
      FUN_0056bca0(&PTR_PTR_00800288,uVar5,(int)uVar5 >> 0x1f,*(uint *)(param_1 + 0x20));
      iVar6 = iVar2;
      if (*(int *)(param_1 + 0x2c) == 0) {
        iVar6 = *(int *)(iVar2 + 0x28);
      }
      FUN_005d7680(iVar6,*(int *)(param_1 + 0x2c));
      _DAT_00000000 = 0xffffffff;
    }
    if (*(int *)(param_1 + 0x2c) == 0) {
      if (*(int *)(iVar2 + 0x28) - *(int *)(*(int *)(iVar2 + 0x28) + -4) != iVar2) {
        ppuVar10 = &PTR_PTR_00800138;
        goto LAB_005d80cc;
      }
    }
    else {
      iVar6 = *(int *)(iVar2 + 0x44);
      if ((*(uint *)(iVar2 + 0x28) < *(uint *)(iVar6 + 0x10)) ||
         ((uint)(*(int *)(iVar6 + 0x14) + *(int *)(iVar6 + 0x10)) <= *(uint *)(iVar2 + 0x28))) {
        ppuVar10 = &PTR_PTR_008001e0;
LAB_005d80cc:
        FUN_0056bca0(ppuVar10);
        iVar6 = iVar2;
        if (*(int *)(param_1 + 0x2c) == 0) {
          iVar6 = *(int *)(iVar2 + 0x28);
        }
        FUN_005d7680(iVar6,*(int *)(param_1 + 0x2c));
        _DAT_00000000 = 0xffffffff;
      }
    }
    iVar2 = *(int *)(iVar2 + 0x3c);
  } while( true );
}

