
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_0042c860(int param_1)

{
  undefined1 local_5c [32];
  int local_3c;
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  *(undefined1 *)(param_1 + 0x4e7) = 1;
  FUN_0052ece0();
  FUN_0054fc10(1,local_5c);
  if (local_3c != -1) {
    *(undefined1 *)(param_1 + 0x4e7) = 0;
  }
  return;
}

