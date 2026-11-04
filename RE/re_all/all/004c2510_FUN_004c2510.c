
void __fastcall FUN_004c2510(undefined4 *param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  cVar1 = FUN_004d2230();
  if (cVar1 == '\0') {
    FUN_004d2250(0);
    cVar1 = FUN_00486cd0();
    if (cVar1 == '\0') {
      uVar4 = *param_1;
      uVar3 = 0xffffffff;
      uVar2 = FUN_004c2590(0xffffffff,uVar4);
      FUN_004d2250(0);
      FUN_0044ecd0(uVar2,uVar3,uVar4);
    }
    FUN_004d2250(0);
    FUN_0044ef40();
  }
  return;
}

