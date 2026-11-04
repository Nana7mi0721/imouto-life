
void FUN_0047e980(undefined1 param_1,void *param_2)

{
  void *pvVar1;
  size_t sVar2;
  int iVar3;
  int *piVar4;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_14;
  int local_10;
  void *local_c;
  
  local_c = param_2;
  local_14 = 0;
  local_10 = 0;
  while( true ) {
    local_c = _memchr(local_c,0x4c,(1000 - (int)local_c) + (int)param_2);
    if (local_c == (void *)0x0) break;
    sVar2 = _strlen("LOOPSTART=");
    iVar3 = _memcmp(local_c,"LOOPSTART=",sVar2);
    pvVar1 = param_2;
    if (iVar3 == 0) {
      sVar2 = _strlen("LOOPSTART=");
      local_1c = 0;
      for (local_20 = (int)local_c + (sVar2 - (int)pvVar1);
          (0x2f < *(byte *)((int)param_2 + local_20) && (*(byte *)((int)param_2 + local_20) < 0x3a))
          ; local_20 = local_20 + 1) {
        local_1c = local_1c * 10 + -0x30 + (uint)*(byte *)((int)param_2 + local_20);
      }
      local_14 = local_1c;
    }
    sVar2 = _strlen("LOOPLENGTH=");
    iVar3 = _memcmp(local_c,"LOOPLENGTH=",sVar2);
    pvVar1 = param_2;
    if (iVar3 == 0) {
      sVar2 = _strlen("LOOPLENGTH=");
      local_24 = 0;
      for (local_28 = (int)local_c + (sVar2 - (int)pvVar1);
          (0x2f < *(byte *)((int)param_2 + local_28) && (*(byte *)((int)param_2 + local_28) < 0x3a))
          ; local_28 = local_28 + 1) {
        local_24 = local_24 * 10 + -0x30 + (uint)*(byte *)((int)param_2 + local_28);
      }
      local_10 = local_24;
    }
    local_c = (void *)((int)local_c + 1);
  }
  if (local_14 != 0) {
    piVar4 = (int *)FUN_004cc020(&param_1);
    *piVar4 = local_14;
  }
  if (local_10 != 0) {
    piVar4 = (int *)FUN_004cc020(&param_1);
    *piVar4 = local_14 + local_10;
  }
  return;
}

