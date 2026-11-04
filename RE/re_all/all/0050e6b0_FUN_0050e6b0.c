
void FUN_0050e6b0(void)

{
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_00a20c40 == 0) {
    FUN_00522420();
    local_8 = DAT_00a37e8c;
    local_4 = DAT_00a37e90;
  }
  else if (DAT_00a37e78 == 0) {
    FUN_005167a0(&local_8,&local_4);
  }
  else {
    local_8 = 0x280;
    local_4 = 0x1e0;
  }
  if (unaff_ESI != (undefined4 *)0x0) {
    *unaff_ESI = local_8;
  }
  if (unaff_EDI != (undefined4 *)0x0) {
    *unaff_EDI = local_4;
  }
  return;
}

