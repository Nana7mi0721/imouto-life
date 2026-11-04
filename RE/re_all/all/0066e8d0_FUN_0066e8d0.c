
void FUN_0066e8d0(int *param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  if (*(char *)((int)param_1 + 9) == '\x10') {
    puVar1 = param_2 + param_1[1];
    puVar2 = param_2;
    for (; param_2 < puVar1; param_2 = param_2 + 2) {
      *puVar2 = *param_2;
      puVar2 = puVar2 + 1;
    }
    *(undefined1 *)((int)param_1 + 9) = 8;
    *(byte *)((int)param_1 + 0xb) = *(byte *)((int)param_1 + 10) << 3;
    param_1[1] = (uint)*(byte *)((int)param_1 + 10) * *param_1;
  }
  return;
}

