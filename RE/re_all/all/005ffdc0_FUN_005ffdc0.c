
void FUN_005ffdc0(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *unaff_ESI;
  
  iVar1 = param_2;
  if ((param_2 == 0) && (param_1[0xd] != 0)) {
    (**(code **)*param_1)(param_1,&DAT_0085eae4,&param_2);
    FUN_006006b0(0x15,unaff_ESI,0);
    (**(code **)(*unaff_ESI + 8))(unaff_ESI);
  }
  FUN_006005c0(param_1,iVar1,param_3);
  return;
}

