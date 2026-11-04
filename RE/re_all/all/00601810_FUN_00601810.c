
int FUN_00601810(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int *param_5,
                undefined4 param_6)

{
  int iVar1;
  
  iVar1 = FUN_006016e0(param_1,param_2,0,param_5,&param_5);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*param_5 + 0x28))(param_5,param_3,param_4,param_6);
    (**(code **)(*param_1 + 8))(param_1);
  }
  return iVar1;
}

