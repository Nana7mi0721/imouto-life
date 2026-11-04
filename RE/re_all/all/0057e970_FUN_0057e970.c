
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0057e970(undefined4 param_1,int param_2,int param_3)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  
  if (DAT_00aa4fa0 == 0) {
    (**(code **)(**(int **)(param_2 + 200) + 0x44))(*(int **)(param_2 + 200),param_3,param_1);
    return 0;
  }
  if (param_3 == 0) {
    fVar2 = 1.0;
  }
  else {
    fVar2 = (float)param_3;
    if (param_3 < 0) {
      fVar2 = fVar2 + _DAT_007d4bd8;
    }
    fVar3 = (float)*(int *)(param_2 + 0x34);
    if (*(int *)(param_2 + 0x34) < 0) {
      fVar3 = fVar3 + _DAT_007d4bd8;
    }
    fVar2 = fVar2 / fVar3;
  }
  piVar1 = *(int **)(param_2 + 200);
  if (DAT_00aa4254 == 0) {
    (**(code **)(*piVar1 + 0x68))(piVar1,fVar2,0);
    return 0;
  }
  (**(code **)(*piVar1 + 0x68))(piVar1,fVar2);
  return 0;
}

