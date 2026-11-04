
undefined4 FUN_0055ac20(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((DAT_00a834f0 == 0) || (iVar3 = FUN_0057e0e0(), iVar3 == 0)) {
    return 0xffffffff;
  }
  FUN_0056da60(&DAT_00cc50e4,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x3aa7);
  if (param_1 == 0) {
    iVar3 = *(int *)(DAT_00a839dc + 0xc);
    iVar1 = DAT_00a839dc;
    while (iVar3 != 0) {
      iVar3 = *(int *)(iVar1 + 4);
      if (*(int *)(iVar3 + 0x24c) == 0) {
LAB_0055ad1a:
        *(undefined4 *)(iVar3 + 0x70) = 0;
      }
      else if ((*(int *)(iVar3 + 0x78) != 0) && (iVar5 = FUN_0057e6a0(iVar3 + 0x78), iVar5 != 0)) {
        if ((*(int *)(iVar3 + 0x70) != 0) && (*(int *)(iVar3 + 0x74) != 0)) {
          FUN_005517f0(iVar3 + 0x78,*(undefined4 *)(iVar3 + 0xd4));
        }
        goto LAB_0055ad1a;
      }
      iVar1 = *(int *)(iVar1 + 0xc);
      iVar3 = *(int *)(iVar1 + 0xc);
    }
  }
  else {
    iVar3 = DAT_00a839dc;
    if (*(int *)(DAT_00a839dc + 0xc) != 0) {
      do {
        iVar5 = *(int *)(iVar3 + 4);
        iVar1 = iVar5 + 0x78;
        if (((*(int *)(iVar5 + 0x78) != 0) && (iVar4 = FUN_0057e6a0(iVar1), iVar4 != 0)) &&
           (*(int *)(iVar5 + 0x70) == 0)) {
          iVar4 = FUN_00551870(iVar1);
          if (iVar4 == -1) {
            *(undefined4 *)(iVar5 + 0x70) = 0;
          }
          else {
            *(undefined4 *)(iVar5 + 0x70) = 1;
            if (iVar4 == 0) {
              *(undefined4 *)(iVar5 + 0x74) = 0;
            }
            else {
              *(undefined4 *)(iVar5 + 0x74) = 1;
              FUN_00551830(iVar1,1);
            }
          }
        }
        piVar2 = (int *)(iVar3 + 0xc);
        iVar3 = *piVar2;
      } while (*(int *)(*piVar2 + 0xc) != 0);
      FUN_0056dac0(&DAT_00cc50e4);
      return 0;
    }
  }
  FUN_0056dac0(&DAT_00cc50e4);
  return 0;
}

