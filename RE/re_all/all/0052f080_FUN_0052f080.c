
undefined4 FUN_0052f080(int param_1,int *param_2)

{
  if (*(int *)(param_1 + 0x93614) == 0) {
    *(undefined4 *)(param_1 + 0x93614) = 1;
    *(int *)(param_1 + 0x93618) = *param_2;
    *(int *)(param_1 + 0x9361c) = param_2[1];
    *(int *)(param_1 + 0x93620) = param_2[2];
    *(int *)(param_1 + 0x93624) = param_2[3];
    return 0;
  }
  if (*param_2 < *(int *)(param_1 + 0x93618)) {
    *(int *)(param_1 + 0x93618) = *param_2;
  }
  if (param_2[1] < *(int *)(param_1 + 0x9361c)) {
    *(int *)(param_1 + 0x9361c) = param_2[1];
  }
  if (*(int *)(param_1 + 0x93620) < param_2[2]) {
    *(int *)(param_1 + 0x93620) = param_2[2];
  }
  if (*(int *)(param_1 + 0x93624) < param_2[3]) {
    *(int *)(param_1 + 0x93624) = param_2[3];
  }
  return 0;
}

