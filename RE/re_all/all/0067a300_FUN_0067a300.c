
void FUN_0067a300(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    if (((*(uint *)(param_1 + 0x7c) & 0x100000) != 0) && (*(code **)(param_1 + 0x68) != (code *)0x0)
       ) {
      (**(code **)(param_1 + 0x68))(param_1,param_2,*(int *)(param_1 + 0x124) + 1);
    }
    if ((*(uint *)(param_1 + 0x7c) & 0x8000) != 0) {
      FUN_0066cd80(param_2,*(int *)(param_1 + 0x124) + 1,~*(uint *)(param_1 + 0x78) >> 7 & 1);
    }
    if ((*(uint *)(param_1 + 0x7c) & 0x10000) != 0) {
      FUN_0066cd30(param_2,*(int *)(param_1 + 0x124) + 1);
    }
    if ((*(byte *)(param_1 + 0x7c) & 4) != 0) {
      FUN_0067a430(param_2,*(int *)(param_1 + 0x124) + 1,*(undefined1 *)(param_1 + 0x158));
    }
    if ((*(byte *)(param_1 + 0x7c) & 0x10) != 0) {
      FUN_0066cd00(param_2,*(int *)(param_1 + 0x124) + 1);
    }
    if ((*(byte *)(param_1 + 0x7c) & 8) != 0) {
      FUN_0067a560(param_2,*(int *)(param_1 + 0x124) + 1,param_1 + 0x1ad);
    }
    if ((*(uint *)(param_1 + 0x7c) & 0x20000) != 0) {
      FUN_0067a7e0(param_2,*(int *)(param_1 + 0x124) + 1);
    }
    if ((*(uint *)(param_1 + 0x7c) & 0x80000) != 0) {
      FUN_0067a8f0(param_2,*(int *)(param_1 + 0x124) + 1);
    }
    if ((*(byte *)(param_1 + 0x7c) & 1) != 0) {
      FUN_0066cee0(param_2,*(int *)(param_1 + 0x124) + 1);
    }
    if ((*(byte *)(param_1 + 0x7c) & 0x20) != 0) {
      FUN_0066cc70(param_2,*(int *)(param_1 + 0x124) + 1);
    }
  }
  return;
}

