
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005d8c60(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1 != (int *)0x0) {
    piVar3 = param_1;
    if (param_2 == 0) {
      piVar3 = (int *)((int)param_1 - param_1[-1]);
    }
    if (*piVar3 != 0x4d454d44) {
      FUN_0056bca0(&DAT_00801a18);
      _DAT_00000000 = 0xffffffff;
    }
    iVar2 = piVar3[0x10];
    iVar1 = iVar2 + 0x74;
    FUN_0056da60(iVar1,"..\\..\\..\\..\\Source\\Library\\Main\\DxHeap.cpp",0x8e9);
    if (*(int *)(iVar2 + 0x2c) == 0) {
      iVar2 = FUN_005d6a70();
      if (iVar2 < 0) {
        FUN_0056bca0(&DAT_00801998);
        FUN_005d7680(param_1,param_2);
        _DAT_00000000 = 0xffffffff;
      }
    }
    if ((*(byte *)((int)piVar3 + 0x16) & 4) == 0) {
      FUN_0056bca0(&DAT_00801940);
      FUN_005d7680(param_1,param_2);
      _DAT_00000000 = 0xffffffff;
    }
    FUN_005d8a70(0);
    FUN_0056dac0(iVar1);
  }
  return 0;
}

