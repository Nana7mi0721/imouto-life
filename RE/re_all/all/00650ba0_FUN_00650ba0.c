
int FUN_00650ba0(undefined4 *param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  
  if ((((param_3 == 0) || (param_4 == 0)) || ((param_3 * param_4) / param_4 != param_3)) ||
     (iVar1 = FUN_006507f0(param_2,param_3 * param_4), iVar1 == 0)) {
    FUN_006512e0(param_1[0x9d],*param_1,s__Failed_to_allocate_memory_for___00a06b77 + 1,param_5,
                 param_3,param_4);
    return 0;
  }
  return iVar1;
}

