
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00652dc0(int param_1)

{
  uint uVar1;
  uint *in_stack_00000014;
  uint *in_stack_00000018;
  uint *in_stack_0000001c;
  
  __ftol();
  uVar1 = __ftol();
  *in_stack_00000014 = uVar1;
  __ftol();
  uVar1 = __ftol();
  *in_stack_00000018 = uVar1;
  __ftol();
  uVar1 = __ftol();
  *in_stack_0000001c = uVar1;
  uVar1 = *in_stack_00000014;
  if (*(uint *)(param_1 + 0x4c) <= *in_stack_00000014) {
    uVar1 = *(uint *)(param_1 + 0x4c);
  }
  *in_stack_00000014 = uVar1;
  uVar1 = *in_stack_00000018;
  if (*(uint *)(param_1 + 0x50) <= *in_stack_00000018) {
    uVar1 = *(uint *)(param_1 + 0x50);
  }
  *in_stack_00000018 = uVar1;
  if (*in_stack_0000001c < *(uint *)(param_1 + 0x54)) {
    *in_stack_0000001c = *in_stack_0000001c;
    return;
  }
  *in_stack_0000001c = *(uint *)(param_1 + 0x54);
  return;
}

