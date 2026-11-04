
void __thiscall
FUN_0060d050(int param_1,undefined4 param_2,undefined4 param_3,int *param_4,undefined4 param_5,
            undefined4 param_6)

{
  uint uVar1;
  
  if (*(int **)(param_1 + 0x74) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x74) + 0x14))(param_2,param_3,param_4,param_5,param_6);
    return;
  }
  uVar1 = 1;
  if (1 < *(int *)(param_1 + 0x3c) * 2 + 1U) {
    do {
      if ((*(byte *)(*(int *)(param_1 + 0x4c) + uVar1 * 8) & 1) != 0) {
        (**(code **)(*param_4 + 4))
                  (*(int *)(param_1 + 0x44) +
                   *(int *)(*(int *)(param_1 + 0x4c) + uVar1 * 8 + 4) * 0x4c);
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(int *)(param_1 + 0x3c) * 2 + 1U);
  }
  return;
}

