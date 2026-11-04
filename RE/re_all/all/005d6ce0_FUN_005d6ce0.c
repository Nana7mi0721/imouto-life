
void __fastcall FUN_005d6ce0(undefined4 param_1,int param_2)

{
  uint *puVar1;
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x38) == 0) {
    *(undefined4 *)
     (param_2 + 0x318 + ((uint)*(byte *)(in_EAX + 0x17) * 0x20 + (uint)*(byte *)(in_EAX + 0x18)) * 4
     ) = *(undefined4 *)(in_EAX + 0x3c);
  }
  else {
    *(undefined4 *)(*(int *)(in_EAX + 0x38) + 0x3c) = *(undefined4 *)(in_EAX + 0x3c);
  }
  if (*(int *)(in_EAX + 0x3c) == 0) {
    *(undefined4 *)
     (param_2 + 0x1318 +
     ((uint)*(byte *)(in_EAX + 0x17) * 0x20 + (uint)*(byte *)(in_EAX + 0x18)) * 4) =
         *(undefined4 *)(in_EAX + 0x38);
  }
  else {
    *(undefined4 *)(*(int *)(in_EAX + 0x3c) + 0x38) = *(undefined4 *)(in_EAX + 0x38);
  }
  *(undefined4 *)(in_EAX + 0x38) = 0;
  *(undefined4 *)(in_EAX + 0x3c) = 0;
  if (*(int *)(param_2 + 0x318 +
              ((uint)*(byte *)(in_EAX + 0x17) * 0x20 + (uint)*(byte *)(in_EAX + 0x18)) * 4) == 0) {
    puVar1 = (uint *)(param_2 + 0x298 + (uint)*(byte *)(in_EAX + 0x17) * 4);
    *puVar1 = *puVar1 & ~(1 << (*(byte *)(in_EAX + 0x18) & 0x1f));
    if (*(int *)(param_2 + 0x298 + (uint)*(byte *)(in_EAX + 0x17) * 4) == 0) {
      *(uint *)(param_2 + 0x294) =
           *(uint *)(param_2 + 0x294) & ~(1 << (*(byte *)(in_EAX + 0x17) & 0x1f));
    }
  }
  return;
}

