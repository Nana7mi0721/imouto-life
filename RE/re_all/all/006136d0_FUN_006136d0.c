
void __thiscall FUN_006136d0(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (*(int *)(param_2 + 0x3c) == 2) {
    uVar1 = *(undefined4 *)(param_2 + 0x30);
  }
  else {
    uVar1 = *(undefined4 *)(param_2 + 0x30);
  }
  FUN_00621410(uVar1);
  if (*(int *)(param_2 + 0x34) == 0) {
    *(undefined4 *)(param_1 + 0x54 + *(int *)(param_2 + 0x3c) * 4) = *(undefined4 *)(param_2 + 0x38)
    ;
  }
  else {
    *(undefined4 *)(*(int *)(param_2 + 0x34) + 0x38) = *(undefined4 *)(param_2 + 0x38);
  }
  if (*(int *)(param_2 + 0x38) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x38) + 0x34) = *(undefined4 *)(param_2 + 0x34);
  }
  (**(code **)(**(int **)(param_1 + 0x60) + 0xc))(param_2,param_3);
  FUN_00646b80(param_2);
  *(undefined1 *)(param_1 + 0x9a) = 1;
  return;
}

