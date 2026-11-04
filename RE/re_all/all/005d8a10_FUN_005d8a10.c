
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005d8a10(int *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = param_1;
  if (param_2 == 0) {
    piVar1 = (int *)((int)param_1 - param_1[-1]);
  }
  if (*piVar1 != 0x4d454d44) {
    FUN_0056bca0(&DAT_008018b0);
    _DAT_00000000 = 0xffffffff;
  }
  if ((*(byte *)((int)piVar1 + 0x16) & 4) == 0) {
    FUN_0056bca0(&DAT_00801840);
    FUN_005d7680(param_1,param_2);
    _DAT_00000000 = 0xffffffff;
  }
  return piVar1[0xb];
}

