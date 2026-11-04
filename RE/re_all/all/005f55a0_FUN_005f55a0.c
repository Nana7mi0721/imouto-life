
undefined4 FUN_005f55a0(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  *param_2 = (int)param_3;
  iVar1 = (*(code *)*param_3)(param_3[6]);
  (**(code **)(*param_2 + 4))(*(undefined4 *)(*param_2 + 0x18),0,0,2);
  iVar2 = (**(code **)*param_2)(((undefined4 *)*param_2)[6]);
  param_2[1] = iVar2 - iVar1;
  (**(code **)(*param_2 + 4))(*(undefined4 *)(*param_2 + 0x18),iVar1,iVar1 >> 0x1f,0);
  FUN_006685d0(param_1,param_2,&LAB_005f5600);
  return 0;
}

