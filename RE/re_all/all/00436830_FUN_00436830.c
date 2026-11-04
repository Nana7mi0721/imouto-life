
void __fastcall FUN_00436830(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  
  *(undefined4 *)(param_1 + 4) = 0xffffffff;
  FUN_004cdbe0();
  FUN_004cd4c0();
  FUN_004cc250();
  FUN_004cd4c0();
  FUN_004cdf30();
  uVar1 = FUN_004cfab0();
  FUN_004cd310(uVar1);
  local_8 = 0;
  while( true ) {
    iVar2 = FUN_004cd340();
    if (iVar2 <= local_8) break;
    uVar1 = 100;
    FUN_004cde80(local_8);
    FUN_004ce970(uVar1);
    local_8 = local_8 + 1;
  }
  uVar1 = FUN_004cfab0();
  FUN_004cde50(uVar1);
  local_c = 0;
  while( true ) {
    iVar2 = FUN_004cd340();
    if (iVar2 <= local_c) break;
    uVar1 = 5;
    FUN_004cde80(local_c);
    FUN_004cc400(uVar1);
    local_c = local_c + 1;
  }
  FUN_004cd310(10);
  iVar2 = FUN_00477850();
  if (0xf < iVar2) {
    for (local_10 = 0; local_10 < 10; local_10 = local_10 + 1) {
      if (local_10 == 0) {
        local_18 = 0xe;
      }
      else {
        local_18 = local_10 + 0xe;
      }
      uVar1 = FUN_004717c0(local_18);
      FUN_004cde80(local_10);
      FUN_004ce970(uVar1);
    }
  }
  return;
}

