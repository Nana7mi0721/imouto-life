
void __fastcall FUN_0047a120(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar2 = FUN_0047a1b0(param_1);
  if ((iVar2 == 3) ||
     ((iVar2 = FUN_0047a1b0(param_1), iVar2 == 2 && (cVar1 = FUN_0047a1e0(), cVar1 != '\0')))) {
    cVar1 = FUN_004d2230();
    if (cVar1 != '\0') {
      FUN_004d21c0(1);
      uVar4 = 0;
      uVar3 = 0;
      FUN_004d2250(0);
      FUN_0044ea60(uVar3,uVar4);
      iVar2 = FUN_004d2250(0);
      *(undefined4 *)(iVar2 + 0x808) = 0;
    }
  }
  else {
    FUN_004d2300();
  }
  return;
}

