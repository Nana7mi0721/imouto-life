
int FUN_00606960(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = param_3;
  if (param_3 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  param_3 = (int *)0x0;
  iVar2 = FUN_00606d60(param_2,&param_3,param_4,&param_4);
  if (-1 < iVar2) {
    (**(code **)(*param_3 + 0x30))(param_3,param_4);
  }
  *puVar1 = param_3;
  return iVar2;
}

