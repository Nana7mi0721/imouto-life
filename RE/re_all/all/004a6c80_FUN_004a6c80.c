
/* WARNING: Removing unreachable block (ram,0x004a6ce3) */
/* WARNING: Removing unreachable block (ram,0x004a6d3b) */
/* WARNING: Removing unreachable block (ram,0x004a6d0f) */
/* WARNING: Removing unreachable block (ram,0x004a6d45) */
/* WARNING: Removing unreachable block (ram,0x004a6d69) */
/* WARNING: Removing unreachable block (ram,0x004a6d75) */
/* WARNING: Removing unreachable block (ram,0x004a6db6) */
/* WARNING: Removing unreachable block (ram,0x004a6d7e) */
/* WARNING: Removing unreachable block (ram,0x004a6dc0) */
/* WARNING: Removing unreachable block (ram,0x004a6e4b) */
/* WARNING: Removing unreachable block (ram,0x004a6e94) */
/* WARNING: Removing unreachable block (ram,0x004a6e68) */
/* WARNING: Removing unreachable block (ram,0x004a6e9e) */
/* WARNING: Removing unreachable block (ram,0x004a6dec) */
/* WARNING: Removing unreachable block (ram,0x004a6e2d) */
/* WARNING: Removing unreachable block (ram,0x004a6df5) */
/* WARNING: Removing unreachable block (ram,0x004a6e37) */
/* WARNING: Removing unreachable block (ram,0x004a6d60) */

undefined4 FUN_004a6c80(void)

{
  undefined1 local_5;
  
  local_5 = 0;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 1;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_5,1);
  }
  else {
    DAT_00a0f844 = 1;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  return 1;
}

