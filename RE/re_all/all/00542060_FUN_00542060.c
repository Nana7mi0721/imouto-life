
int FUN_00542060(char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*param_1 == '\0') {
    iVar1 = *(int *)(param_1 + 0x430) * *(int *)(param_1 + 0x42c);
  }
  else {
    switch(*param_1) {
    case '\x01':
      iVar1 = 8;
      break;
    case '\x02':
    case '\x03':
    case '\x04':
    case '\x05':
      iVar1 = 0x10;
      break;
    default:
      return -1;
    }
    iVar1 = ((int)(*(int *)(param_1 + 0x42c) + (*(int *)(param_1 + 0x42c) >> 0x1f & 3U)) >> 2) *
            ((int)(*(int *)(param_1 + 0x428) + (*(int *)(param_1 + 0x428) >> 0x1f & 3U)) >> 2) *
            iVar1;
  }
  iVar3 = *(int *)(param_1 + 0x438);
  if (1 < iVar3) {
    iVar4 = 0;
    iVar2 = iVar1;
    iVar1 = iVar4;
    if (0 < iVar3) {
      do {
        iVar1 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
        iVar4 = iVar4 + iVar2;
        if (iVar1 < 8) {
          iVar1 = 8;
        }
        iVar3 = iVar3 + -1;
        iVar2 = iVar1;
      } while (iVar3 != 0);
      return iVar4;
    }
  }
  return iVar1;
}

