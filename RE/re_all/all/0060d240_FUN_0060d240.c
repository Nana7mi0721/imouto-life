
void __thiscall FUN_0060d240(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_2 < param_3) {
    param_3 = param_3 - param_2;
    puVar2 = (undefined4 *)(param_2 * 0x10 + 8 + param_4);
    do {
      if (puVar2 != (undefined4 *)0x8) {
        puVar1 = (undefined4 *)(*(int *)(param_1 + 0xc) + (-8 - param_4) + (int)puVar2);
        puVar2[-2] = *puVar1;
        puVar2[-1] = puVar1[1];
        *puVar2 = puVar1[2];
        puVar2[1] = puVar1[3];
      }
      puVar2 = puVar2 + 4;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

