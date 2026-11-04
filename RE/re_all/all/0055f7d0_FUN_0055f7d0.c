
undefined4 FUN_0055f7d0(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (*(int *)(param_1 + 0x1208) == 1) {
    FUN_0055e7e0(*(undefined4 *)(param_1 + 4));
  }
  else if (*(int *)(param_1 + 0xc4) != 0) {
    FUN_0055f370(*(undefined4 *)(param_1 + 4));
  }
  if (*(int *)(param_1 + 0x40) != 0) {
    FUN_0056da60(&DAT_00a83570,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x1b1);
    FUN_00580810(param_1 + 0x30);
    FUN_0056dac0(&DAT_00a83570);
    if (*(int *)(param_1 + 0x44) != 0) {
      *(undefined4 *)(param_1 + 0x44) = 0;
      FUN_0056da60(&DAT_00a83a30,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x1bf);
      FUN_00580810(param_1 + 0x48);
      FUN_0056dac0(&DAT_00a83a30);
    }
  }
  if (*(int *)(param_1 + 0x58) != 0) {
    FUN_00580810(param_1 + 0x5c);
  }
  if (*(int *)(param_1 + 0x1208) == 0) {
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x70)) {
      piVar4 = (int *)(param_1 + 0xc4);
      do {
        if (*piVar4 != 0) {
          FUN_0057e620(piVar4);
          iVar2 = piVar4[0x13];
          if (iVar2 != 0) {
            *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + -1;
            if ((*(int *)(iVar2 + 0xc) < 1) && (-1 < *(int *)(iVar2 + 0xc))) {
              FUN_0056e1d0(iVar2);
            }
            piVar4[0x13] = 0;
          }
          *piVar4 = 0;
        }
        iVar3 = iVar3 + 1;
        piVar4 = piVar4 + 0x6e;
      } while (iVar3 < *(int *)(param_1 + 0x70));
    }
    piVar4 = *(int **)(param_1 + 0x2500);
    if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, **(int **)(param_1 + 0x2500) == 0)) {
      if (*(int *)(param_1 + 0x24fc) != 0) {
        FUN_0056e1d0(*(int *)(param_1 + 0x24fc));
      }
      FUN_0056e1d0(*(undefined4 *)(param_1 + 0x2500));
    }
    *(undefined4 *)(param_1 + 0x2500) = 0;
    *(undefined4 *)(param_1 + 0x24fc) = 0;
  }
  else if (*(int *)(param_1 + 0x1208) == 1) {
    uVar1 = *(uint *)(param_1 + 0x1210);
    if ((((uVar1 != 0xffffffff) && (DAT_00cc4db0 != 0)) && (-1 < (int)uVar1)) &&
       ((((uVar1 & 0x7c000000) == DAT_00cc4dd8 && ((int)(uVar1 & 0xffff) < DAT_00cc4de0)) &&
        ((piVar4 = *(int **)(DAT_00cc4db4 + (uVar1 & 0xffff) * 4), piVar4 != (int *)0x0 &&
         ((*piVar4 * 0x10000 == (uVar1 & 0x3ff0000) && (piVar4[4] == 0)))))))) {
      piVar4[0x485] = piVar4[0x485] + -1;
      if ((*(int *)(param_1 + 0x1210) != *(int *)(param_1 + 4)) && (piVar4[0x487] == 1)) {
        FUN_00580b80(*(int *)(param_1 + 0x1210));
      }
    }
    if (*(int *)(param_1 + 0x1214) != 0) {
      *(undefined4 *)(param_1 + 0x121c) = 1;
      return 1;
    }
    FUN_0056da60(&DAT_00a837b0,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x208);
    FUN_00580810(param_1 + 0x24e8);
    FUN_0056dac0(&DAT_00a837b0);
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x24b4)) {
      piVar4 = (int *)(param_1 + 0x1238);
      do {
        FUN_00597060(piVar4 + 0xb);
        if (*piVar4 != 0) {
          FUN_0056e1d0(*piVar4);
        }
        if (((*(char *)(param_1 + 0x24b0 + iVar3) == '\x01') && (piVar4[-1] == 3)) &&
           (piVar4[0x14] != 0)) {
          (*(code *)piVar4[0x13])(piVar4[0x14]);
        }
        if (piVar4[8] != 0) {
          (*(code *)piVar4[7])(piVar4[8]);
        }
        iVar3 = iVar3 + 1;
        piVar4 = piVar4 + 0x128;
      } while (iVar3 < *(int *)(param_1 + 0x24b4));
    }
    if (*(int *)(param_1 + 0xc4) != 0) {
      FUN_005517a0(param_1 + 0xc4);
      return 0;
    }
  }
  return 0;
}

