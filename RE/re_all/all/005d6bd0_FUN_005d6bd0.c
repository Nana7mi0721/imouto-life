
void __fastcall FUN_005d6bd0(int param_1)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x38) == 0) {
    *(undefined4 *)(param_1 + 0x2318) = *(undefined4 *)(in_EAX + 0x3c);
  }
  else {
    *(undefined4 *)(*(int *)(in_EAX + 0x38) + 0x3c) = *(undefined4 *)(in_EAX + 0x3c);
  }
  if (*(int *)(in_EAX + 0x3c) == 0) {
    *(undefined4 *)(param_1 + 0x231c) = *(undefined4 *)(in_EAX + 0x38);
    *(undefined4 *)(in_EAX + 0x3c) = 0;
    *(undefined4 *)(in_EAX + 0x38) = 0;
    return;
  }
  *(undefined4 *)(*(int *)(in_EAX + 0x3c) + 0x38) = *(undefined4 *)(in_EAX + 0x38);
  *(undefined4 *)(in_EAX + 0x3c) = 0;
  *(undefined4 *)(in_EAX + 0x38) = 0;
  return;
}

