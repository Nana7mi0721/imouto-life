
void __thiscall
FUN_0060c600(int param_1,undefined4 param_2,undefined4 param_3,int *param_4,undefined4 param_5,
            undefined4 param_6)

{
  uint uVar1;
  uint uVar2;
  
  if (*(int **)(param_1 + 0x6c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x6c) + 0x14))(param_2,param_3,param_4,param_5,param_6);
    return;
  }
  uVar2 = 1;
  if (1 < (uint)*(ushort *)(param_1 + 0x38) * 2 + 1) {
    uVar1 = 1;
    do {
      if ((*(byte *)(*(int *)(param_1 + 0x44) + uVar1 * 4) & 1) != 0) {
        (**(code **)(*param_4 + 4))
                  ((uint)*(ushort *)(*(int *)(param_1 + 0x44) + uVar1 * 4 + 2) * 0x40 +
                   *(int *)(param_1 + 0x3c));
      }
      uVar2 = uVar2 + 1;
      uVar1 = uVar2 & 0xffff;
    } while (uVar1 < (uint)*(ushort *)(param_1 + 0x38) * 2 + 1);
  }
  return;
}

