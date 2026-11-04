
undefined4 FUN_0055bb40(undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  (*(code *)param_1[1])(param_1[6],0,0,2);
  uVar1 = (*(code *)*param_1)(param_1[6]);
  (*(code *)param_1[1])(param_1[6],0,0,0);
  iVar2 = FUN_0056e030(uVar1,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x40ca);
  if (iVar2 == 0) {
    uVar1 = FUN_0056bca0(&DAT_007d6384);
    return uVar1;
  }
  (*(code *)param_1[2])(iVar2,uVar1,1,param_1[6]);
  *param_2 = iVar2;
  *param_3 = uVar1;
  return 0;
}

