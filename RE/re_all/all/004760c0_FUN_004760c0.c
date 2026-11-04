
int FUN_004760c0(void)

{
  int iVar1;
  int *piVar2;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  for (local_c = 0; local_c < 3; local_c = local_c + 1) {
    local_10 = 0;
    while( true ) {
      iVar1 = FUN_004717c0(local_c + 1);
      if (iVar1 <= local_10) break;
      piVar2 = (int *)FUN_004cc020(&local_10);
      if (*piVar2 != 0) {
        local_8 = local_8 + 1;
      }
      local_10 = local_10 + 1;
    }
  }
  return local_8;
}

