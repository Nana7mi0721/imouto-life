
void FUN_00581340(undefined4 *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  
  if ((((-1 < param_3) && (-1 < param_4)) && (param_3 + param_5 <= *(int *)(param_2 + 4))) &&
     (param_4 + param_6 <= *(int *)(param_2 + 8))) {
    param_1[1] = param_5;
    param_1[2] = param_6;
    *param_1 = 0x12345678;
    iVar1 = (uint)*(byte *)(*(int *)(*(int *)(param_2 + 0x14) + 0x14) + 4) * param_3 +
            *(int *)(*(int *)(param_2 + 0x14) + 0xc) * param_4;
    param_1[3] = *(int *)(param_2 + 0xc) + iVar1;
    if (*(int *)(*(int *)(param_2 + 0x14) + 0x48) != 0) {
      param_1[4] = *(int *)(param_2 + 0x10) + iVar1;
      param_1[5] = *(undefined4 *)(param_2 + 0x14);
      **(int **)(param_2 + 0x14) = **(int **)(param_2 + 0x14) + 1;
      return;
    }
    param_1[4] = 0;
    param_1[5] = *(undefined4 *)(param_2 + 0x14);
    **(int **)(param_2 + 0x14) = **(int **)(param_2 + 0x14) + 1;
  }
  return;
}

