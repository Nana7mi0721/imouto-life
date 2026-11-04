
undefined4 FUN_005f8a20(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != (int *)0x0) {
    FUN_006ac700(param_1 + 0x94);
    FUN_006acb60(param_1 + 0x78);
    FUN_006a8490(param_1 + 0x1e);
    if ((param_1[0x12] != 0) && (param_1[0xd] != 0)) {
      iVar2 = 0;
      if (0 < param_1[0xd]) {
        iVar1 = 0;
        iVar3 = 0;
        do {
          FUN_006abab0(iVar3 + param_1[0x12]);
          FUN_006ab9f0(param_1[0x13] + iVar1);
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0x20;
          iVar1 = iVar1 + 0x10;
        } while (iVar2 < param_1[0xd]);
      }
      _free((void *)param_1[0x12]);
      _free((void *)param_1[0x13]);
    }
    if ((void *)param_1[0xf] != (void *)0x0) {
      _free((void *)param_1[0xf]);
    }
    if ((void *)param_1[0x11] != (void *)0x0) {
      _free((void *)param_1[0x11]);
    }
    if ((void *)param_1[0x10] != (void *)0x0) {
      _free((void *)param_1[0x10]);
    }
    if ((void *)param_1[0xe] != (void *)0x0) {
      _free((void *)param_1[0xe]);
    }
    FUN_006a86c0(param_1 + 6);
    if ((*param_1 != 0) && ((code *)param_1[0xb2] != (code *)0x0)) {
      (*(code *)param_1[0xb2])(*param_1);
    }
    FUN_0056d380(param_1,0,0x2d0);
  }
  return 0;
}

