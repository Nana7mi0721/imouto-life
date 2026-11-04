
void FUN_00660b00(int param_1,float *param_2,int param_3)

{
  float fVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  int local_14;
  
  puVar3 = *(undefined2 **)(param_1 + 0xc);
  if (0 < param_3) {
    local_14 = param_3;
    do {
      fVar1 = *param_2;
      param_2 = param_2 + 1;
      uVar2 = FUN_0065e820((double)fVar1,*(undefined4 *)(param_1 + 4));
      *puVar3 = uVar2;
      puVar3 = puVar3 + 1;
      local_14 = local_14 + -1;
    } while (local_14 != 0);
  }
  return;
}

