
uint * FUN_006afca0(int param_1,int param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  uint *_Memory;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  uint local_88 [34];
  
  iVar5 = param_3;
  if (param_3 == 0) {
    iVar5 = param_2;
  }
  _Memory = _malloc(iVar5 << 2);
  puVar7 = local_88;
  iVar8 = 0;
  for (iVar5 = 0x21; puVar7 = puVar7 + 1, iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = 0;
  }
  if (0 < param_2) {
    puVar7 = _Memory;
    do {
      iVar5 = (int)(char)*(byte *)(param_1 + iVar8);
      if (iVar5 < 1) {
        if (param_3 == 0) {
          puVar7 = puVar7 + 1;
        }
      }
      else {
        uVar4 = local_88[iVar5 + 1];
        puVar3 = local_88 + iVar5 + 1;
        if ((iVar5 < 0x20) && (uVar4 >> (*(byte *)(param_1 + iVar8) & 0x1f) != 0)) {
          _free(_Memory);
          return (uint *)0x0;
        }
        *puVar7 = uVar4;
        puVar7 = puVar7 + 1;
        iVar6 = iVar5;
        do {
          if ((*puVar3 & 1) != 0) {
            if (iVar6 == 1) {
              local_88[2] = local_88[2] + 1;
            }
            else {
              local_88[iVar6 + 1] = local_88[iVar6] << 1;
            }
            break;
          }
          iVar6 = iVar6 + -1;
          *puVar3 = *puVar3 + 1;
          puVar3 = puVar3 + -1;
        } while (0 < iVar6);
        iVar6 = iVar5 + 1;
        if (iVar6 < 0x21) {
          puVar3 = local_88 + iVar5 + 2;
          do {
            uVar2 = *puVar3;
            if (uVar2 >> 1 != uVar4) break;
            *puVar3 = puVar3[-1] << 1;
            iVar6 = iVar6 + 1;
            puVar3 = puVar3 + 1;
            uVar4 = uVar2;
          } while (iVar6 < 0x21);
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < param_2);
  }
  iVar5 = 1;
  if (param_3 != 1) {
    puVar7 = local_88 + 2;
    do {
      if ((*puVar7 & 0xffffffffU >> (0x20U - (char)iVar5 & 0x1f)) != 0) {
        _free(_Memory);
        return (uint *)0x0;
      }
      iVar5 = iVar5 + 1;
      puVar7 = puVar7 + 1;
    } while (iVar5 < 0x21);
  }
  local_88[0] = 0;
  if (0 < param_2) {
    puVar7 = _Memory;
    do {
      uVar4 = 0;
      iVar5 = 0;
      cVar1 = *(char *)(local_88[0] + param_1);
      if (0 < cVar1) {
        do {
          uVar4 = uVar4 * 2 | *puVar7 >> ((byte)iVar5 & 0x1f) & 1;
          iVar5 = iVar5 + 1;
        } while (iVar5 < cVar1);
      }
      if ((param_3 == 0) || (cVar1 != '\0')) {
        *puVar7 = uVar4;
        puVar7 = puVar7 + 1;
      }
      local_88[0] = local_88[0] + 1;
    } while ((int)local_88[0] < param_2);
  }
  return _Memory;
}

