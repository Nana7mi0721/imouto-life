
void __thiscall FUN_0049b960(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int local_8;
  
  *param_3 = 0;
  for (local_8 = 0; (local_8 < 0x1f && (*(int *)(param_1 + 0x14 + local_8 * 4) < *param_2));
      local_8 = local_8 + 1) {
    iVar1 = (local_8 + 1) * *(int *)(param_1 + 0x10);
    *param_3 = (int)(iVar1 + (iVar1 >> 0x1f & 0x1fU)) >> 5;
  }
  while ((iVar1 = FUN_004d3180(), *param_3 < iVar1 &&
         (iVar1 = FUN_004d31e0(*param_3), *(int *)(iVar1 + 0x26c) < *param_2))) {
    *param_3 = *param_3 + 1;
  }
  return;
}

