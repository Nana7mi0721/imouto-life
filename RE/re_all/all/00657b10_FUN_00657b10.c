
int FUN_00657b10(float param_1,int param_2,double *param_3)

{
  int iVar1;
  float10 fVar2;
  undefined4 local_8;
  undefined4 uStack_4;
  
  if ((*(int *)(param_2 + 8) != 1) || (*(int *)(param_2 + 0xc) != 0)) {
    return 1;
  }
  switch(*(undefined2 *)(param_2 + 2)) {
  case 1:
    FUN_00655750(param_1,param_2,&param_1);
    *param_3 = (double)((uint)param_1 & 0xff);
    return 0;
  default:
    iVar1 = 2;
    break;
  case 3:
    FUN_00655760(param_1,param_2,&param_1);
    *param_3 = (double)((uint)param_1 & 0xffff);
    return 0;
  case 4:
    FUN_00655790(param_1,param_2,&param_1);
    *param_3 = (double)(uint)param_1;
    return 0;
  case 5:
    iVar1 = FUN_00659ce0(param_1,param_2,param_3);
    return iVar1;
  case 6:
    FUN_00655750(param_1,param_2,&param_1);
    *param_3 = (double)(int)param_1._0_1_;
    return 0;
  case 8:
    FUN_00655760(param_1,param_2,&param_1);
    *param_3 = (double)(int)param_1._0_2_;
    return 0;
  case 9:
    FUN_00655790(param_1,param_2,&param_1);
    *param_3 = (double)(int)param_1;
    return 0;
  case 10:
    iVar1 = FUN_00659db0(param_1,param_2,param_3);
    return iVar1;
  case 0xb:
    FUN_00659e70(param_1,param_2,&param_1);
    *param_3 = (double)param_1;
    return 0;
  case 0xc:
    iVar1 = FUN_00659ea0(param_1,param_2,param_3);
    return iVar1;
  case 0x10:
    iVar1 = FUN_006557c0(param_1,param_2,&local_8);
    if (iVar1 == 0) {
      fVar2 = (float10)FUN_006512c0(local_8,uStack_4);
      *param_3 = (double)fVar2;
      return 0;
    }
    break;
  case 0x11:
    iVar1 = FUN_006557c0(param_1,param_2,&local_8);
    if (iVar1 == 0) {
      *param_3 = (double)CONCAT44(uStack_4,local_8);
      return 0;
    }
  }
  return iVar1;
}

