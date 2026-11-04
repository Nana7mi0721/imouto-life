
undefined4 FUN_005fab40(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_0056d960(param_1 + 0x240);
  if (iVar1 != 0) {
    FUN_0056da60(param_1,s_D__DxLib_Develop_Source_Library__00a05f80,0xe02);
    *(undefined4 *)(param_1 + 0x228) = 1;
    FUN_0056dac0(param_1);
    FUN_0056da60(param_1,s_D__DxLib_Develop_Source_Library__00a05f80,0xe0c);
    iVar1 = *(int *)(param_1 + 0x220);
    FUN_0056dac0(param_1);
    while (iVar1 != 3) {
      FUN_0056da20(1);
      FUN_0056da60(param_1,s_D__DxLib_Develop_Source_Library__00a05f80,0xe0c);
      iVar1 = *(int *)(param_1 + 0x220);
      FUN_0056dac0(param_1);
    }
    FUN_0056d940(param_1 + 0x240);
  }
  if (*(int *)(param_1 + 0x4e4) != 0) {
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x4e8)) {
      piVar2 = (int *)(*(int *)(param_1 + 0x4e4) + 0xc);
      do {
        if (piVar2[-1] != 0) {
          FUN_0056e1d0(piVar2[-1]);
          piVar2[-1] = 0;
        }
        if (*piVar2 != 0) {
          FUN_0056e1d0(*piVar2);
          *piVar2 = 0;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 10;
      } while (iVar1 < *(int *)(param_1 + 0x4e8));
    }
    FUN_0056e1d0(*(undefined4 *)(param_1 + 0x4e4));
    *(undefined4 *)(param_1 + 0x4e4) = 0;
  }
  FUN_005fb150(param_1,0);
  if (*(int *)(param_1 + 0x4b4) != 0) {
    FUN_0056e1d0(*(int *)(param_1 + 0x4b4));
    *(undefined4 *)(param_1 + 0x4b4) = 0;
  }
  if (*(int *)(param_1 + 0x4c0) != 0) {
    FUN_0056e1d0(*(int *)(param_1 + 0x4c0));
    *(undefined4 *)(param_1 + 0x4c0) = 0;
  }
  if (*(int *)(param_1 + 0x4bc) != 0) {
    FUN_0056e1d0(*(int *)(param_1 + 0x4bc));
    *(undefined4 *)(param_1 + 0x4bc) = 0;
  }
  FUN_005421c0(param_1 + 0x4ec);
  if (*(int *)(param_1 + 0x948) != -1) {
    FUN_00515700(*(undefined4 *)(param_1 + 0x948),0);
    *(undefined4 *)(param_1 + 0x948) = 0xffffffff;
  }
  if (*(int *)(param_1 + 0x94c) != -1) {
    FUN_00515700(*(undefined4 *)(param_1 + 0x94c),0);
    *(undefined4 *)(param_1 + 0x94c) = 0xffffffff;
  }
  FUN_006a8490(param_1 + 0x298);
  FUN_006b8850(param_1 + 0x498);
  FUN_006b8a00(param_1 + 0x488);
  FUN_006b8820(param_1 + 0x420);
  FUN_006a86c0(param_1 + 0x26c);
  FUN_0056da50(param_1);
  FUN_0056e1d0(param_1);
  return 0;
}

