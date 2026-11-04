
undefined4 FUN_0057ee40(int param_1,uint param_2)

{
  if (DAT_00aa4fa0 == 0) {
    (**(code **)(**(int **)(param_1 + 200) + 0x34))(*(int **)(param_1 + 200),param_2);
    return 0;
  }
  *(uint *)(param_1 + 0x54) = param_2 / *(ushort *)(param_1 + 0x3c);
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x54);
  (**(code **)(**(int **)(param_1 + 200) + 0x58))(*(int **)(param_1 + 200));
  return 0;
}

