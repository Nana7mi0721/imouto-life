
void __thiscall FUN_0061be00(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  
  iVar3 = param_3;
  iVar2 = param_2;
  param_2 = param_3;
  if (*(char *)(param_1 + 8) == '\0') {
    param_2 = iVar2;
  }
  param_3 = iVar2;
  if (*(char *)(param_1 + 8) == '\0') {
    param_3 = iVar3;
  }
  piVar1 = *(int **)(param_3 + 0xc0);
  if (((0x14 < piVar1[1]) && (piVar1[1] < 0x1e)) && (*(int *)(*(int *)(param_2 + 0xc0) + 4) < 0x14))
  {
    fVar4 = (float10)(**(code **)(*piVar1 + 0x28))();
    *(undefined4 *)(param_5 + 4) = *(undefined4 *)(param_1 + 0x4c);
    FUN_0061bbc0((float)fVar4,param_4,param_5);
    iVar2 = *(int *)(param_1 + 0x4c);
    *(int *)(iVar2 + 0x294) = param_2;
    *(int *)(iVar2 + 0x298) = param_3;
    (**(code **)(*piVar1 + 0x2c))(param_1 + 0xc,param_1 + 0x18,param_1 + 0x28);
    if (*(int *)(*(int *)(param_5 + 4) + 0x29c) != 0) {
      if (*(int *)(*(int *)(param_5 + 4) + 0x294) != *(int *)(param_5 + 0x88)) {
        FUN_00616dc0(param_5 + 0x48,param_5 + 8);
        return;
      }
      FUN_00616dc0(param_5 + 8,param_5 + 0x48);
    }
  }
  return;
}

