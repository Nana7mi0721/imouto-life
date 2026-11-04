
undefined4 FUN_0055c4d0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  if ((DAT_00a834f0 == 0) || (iVar1 = FUN_0057e0e0(), iVar1 == 0)) {
    return 0xffffffff;
  }
  FUN_0056da60(&DAT_00cc4df4,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0xa5f);
  if (param_1 == 0) {
    if (*(int *)(DAT_00cc4dc4 + 0xc) != 0) {
      iVar1 = DAT_00cc4dc4;
      do {
        piVar5 = (int *)(*(int *)(iVar1 + 4) + 0x74);
        piVar4 = (int *)(*(int *)(iVar1 + 4) + 0xc4);
        iVar3 = 10;
        do {
          if ((*piVar4 != 0) && (iVar2 = FUN_0057e6a0(piVar4), iVar2 != 0)) {
            if ((*piVar5 != 0) && (piVar5[10] != 0)) {
              FUN_005517f0(piVar4,piVar4[0x17]);
            }
            *piVar5 = 0;
          }
          piVar5 = piVar5 + 1;
          piVar4 = piVar4 + 0x6e;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
        iVar1 = *(int *)(iVar1 + 0xc);
      } while (*(int *)(iVar1 + 0xc) != 0);
    }
    iVar1 = DAT_00a83cb4;
    if (DAT_00a83cb0 != 0) {
      iVar3 = DAT_00a83cb4 * 0x77;
      if ((&DAT_00a83cb8)[iVar3] != 0) {
        *(undefined4 *)(&DAT_00a83d14 + DAT_00a83cb4 * 0x1dc) = 1;
        if (DAT_00a83c64 == 0) {
          FUN_0057e6b0(&DAT_00a83cb8 + iVar3,1);
        }
        else {
          (&DAT_00a83d08)[iVar1 * 0x77] = 1;
        }
      }
    }
  }
  else {
    iVar1 = *(int *)(DAT_00cc4dc4 + 0xc);
    iVar3 = DAT_00cc4dc4;
    while (iVar1 != 0) {
      piVar5 = (int *)(*(int *)(iVar3 + 4) + 0x74);
      piVar4 = (int *)(*(int *)(iVar3 + 4) + 0xc4);
      iVar1 = 10;
      do {
        if (((*piVar4 != 0) && (iVar2 = FUN_0057e6a0(piVar4), iVar2 != 0)) && (*piVar5 == 0)) {
          if (*piVar4 != 0) {
            if (DAT_00a83c64 == 0) {
              iVar2 = FUN_0057e790(piVar4);
            }
            else {
              iVar2 = piVar4[0x14];
            }
            if (iVar2 != -1) {
              *piVar5 = 1;
              if (iVar2 == 0) {
                piVar5[10] = 0;
              }
              else {
                piVar5[10] = 1;
                FUN_00551830(piVar4,1);
              }
              goto LAB_0055c58f;
            }
          }
          *piVar5 = 0;
        }
LAB_0055c58f:
        piVar5 = piVar5 + 1;
        piVar4 = piVar4 + 0x6e;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      iVar3 = *(int *)(iVar3 + 0xc);
      iVar1 = *(int *)(iVar3 + 0xc);
    }
    if (DAT_00a83cb0 != 0) {
      if ((&DAT_00a83cb8)[DAT_00a83cb4 * 0x77] != 0) {
        if (DAT_00a83c64 == 0) {
          FUN_0057e730(&DAT_00a83cb8 + DAT_00a83cb4 * 0x77,0);
        }
        else {
          (&DAT_00a83d08)[DAT_00a83cb4 * 0x77] = 0;
        }
      }
    }
  }
  FUN_0056dac0(&DAT_00cc4df4);
  return 0;
}

