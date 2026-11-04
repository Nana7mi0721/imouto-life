
int FUN_00657880(uint param_1,int param_2,float *param_3)

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
    *param_3 = (float)(param_1 & 0xff);
    return 0;
  default:
    iVar1 = 2;
    break;
  case 3:
    FUN_00655760(param_1,param_2,&param_1);
    *param_3 = (float)(param_1 & 0xffff);
    return 0;
  case 4:
    FUN_00655790(param_1,param_2,&param_1);
    *param_3 = (float)param_1;
    return 0;
  case 5:
    iVar1 = FUN_00659ce0(param_1,param_2,&local_8);
    if (iVar1 == 0) {
      *param_3 = (float)(double)CONCAT44(uStack_4,local_8);
      return 0;
    }
    break;
  case 6:
    FUN_00655750(param_1,param_2,&param_1);
    *param_3 = (float)(int)(char)param_1;
    return 0;
  case 8:
    FUN_00655760(param_1,param_2,&param_1);
    *param_3 = (float)(int)(short)param_1;
    return 0;
  case 9:
    FUN_00655790(param_1,param_2,&param_1);
    *param_3 = (float)(int)param_1;
    return 0;
  case 10:
    iVar1 = FUN_00659db0(param_1,param_2,&local_8);
    if (iVar1 == 0) {
      *param_3 = (float)(double)CONCAT44(uStack_4,local_8);
      return 0;
    }
    break;
  case 0xb:
    FUN_00659e70(param_1,param_2,param_3);
    return 0;
  case 0xc:
    iVar1 = FUN_00659ea0(param_1,param_2,&local_8);
    if (iVar1 == 0) {
      *param_3 = (float)(double)CONCAT44(uStack_4,local_8);
      return 0;
    }
    break;
  case 0x10:
    iVar1 = FUN_006557c0(param_1,param_2,&local_8);
    if (iVar1 == 0) {
      fVar2 = (float10)FUN_006512a0(local_8,uStack_4);
      *param_3 = (float)fVar2;
      return 0;
    }
    break;
  case 0x11:
    iVar1 = FUN_006557c0(param_1,param_2,&local_8);
    if (iVar1 == 0) {
      *param_3 = (float)CONCAT44(uStack_4,local_8);
      return 0;
    }
  }
  return iVar1;
}

