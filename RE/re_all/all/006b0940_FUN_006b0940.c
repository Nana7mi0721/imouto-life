
int FUN_006b0940(int param_1,int param_2,undefined4 param_3)

{
  if (-1 < param_2) {
    if (param_2 < *(int *)(*(int *)(param_1 + 0xc) + 4)) {
      FUN_00797570(param_3,*(undefined4 *)(*(int *)(param_1 + 0x14) + param_2 * 4),
                   (int)*(char *)(*(int *)(*(int *)(param_1 + 0xc) + 8) + param_2));
      return (int)*(char *)(*(int *)(*(int *)(param_1 + 0xc) + 8) + param_2);
    }
  }
  return 0;
}

