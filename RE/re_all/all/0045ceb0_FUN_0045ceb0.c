
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __fastcall FUN_0045ceb0(undefined4 param_1)

{
  bool bVar1;
  
  if (DAT_00a14092 == '\0') {
    FUN_0045ce60(param_1);
  }
  bVar1 = DAT_00a14062 == '\0';
  if (bVar1) {
    DAT_00a14092 = '\0';
    DAT_00a14062 = '\x01';
    _DAT_00a14098 = DAT_00a1409c;
  }
  return bVar1;
}

