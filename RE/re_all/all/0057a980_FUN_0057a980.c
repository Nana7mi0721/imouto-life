
void FUN_0057a980(void)

{
  int iVar1;
  UINT UVar2;
  
  iVar1 = FUN_0056cec0();
  if (iVar1 != 0) {
    return;
  }
  FUN_0056ced0(0x4b0);
  UVar2 = GetOEMCP();
  if (UVar2 < 0x3b7) {
    if (UVar2 == 0x3b6) {
      FUN_0056ceb0(3);
      FUN_0056d890(0x3b6);
      return;
    }
    if (UVar2 != 0x3a4) {
      if (UVar2 == 0x3a8) {
        FUN_0056ceb0(4);
        FUN_0056d890(0x3a8);
        return;
      }
      if (UVar2 == 0x3b5) {
        FUN_0056ceb0(2);
        FUN_0056d890(0x3b5);
        return;
      }
    }
  }
  else {
    if (UVar2 == 0x4e4) {
      FUN_0056ceb0(5);
      FUN_0056d890(0x4e4);
      return;
    }
    if (UVar2 == 0x7ffc) {
      FUN_0056ceb0(6);
      FUN_0056d890(0x7ffc);
      return;
    }
  }
  FUN_0056ceb0(1);
  FUN_0056d890(0x3a4);
  return;
}

