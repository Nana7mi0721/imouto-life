
void __fastcall FUN_00595540(uint *param_1)

{
  int in_EAX;
  longlong lVar1;
  
  FUN_0056cf70();
  *(uint *)(in_EAX + 0x208) = *param_1 >> 4 & 1;
  lVar1 = __allmul(param_1[7],0,0,1);
  *(ulonglong *)(in_EAX + 0x210) = lVar1 + (ulonglong)param_1[8];
  FUN_0050f690(param_1 + 1,in_EAX + 0x218);
  FUN_0050f690(param_1 + 5,in_EAX + 0x230);
  return;
}

