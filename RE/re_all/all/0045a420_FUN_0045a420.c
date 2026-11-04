
void FUN_0045a420(void)

{
  char cVar1;
  uint *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  char cVar6;
  byte bVar7;
  int local_20;
  int local_1c;
  int local_18;
  
  puVar2 = (uint *)FUN_004ce990(1);
  if (*puVar2 >> 0x1c == 0) {
    puVar2 = (uint *)FUN_004ce990(1);
    cVar1 = '\x01' - ((*puVar2 & 0x300) != 0);
    puVar2 = (uint *)FUN_004ce990(1);
    cVar6 = '\x01' - ((*puVar2 & 0x200) != 0);
    puVar2 = (uint *)FUN_004ce990(1);
    if ((*puVar2 & 1) != 0) {
      DAT_00a14ad5 = cVar6;
      DAT_00a14adc = cVar1;
    }
    puVar2 = (uint *)FUN_004ce990(1);
    if ((*puVar2 & 2) != 0) {
      DAT_00a14ad6 = cVar6;
      DAT_00a14add = cVar1;
    }
    puVar2 = (uint *)FUN_004ce990(1);
    if ((*puVar2 & 4) != 0) {
      DAT_00a14ad7 = cVar6;
      DAT_00a14ade = cVar1;
    }
    puVar2 = (uint *)FUN_004ce990(1);
    if ((*puVar2 & 0x10) != 0) {
      DAT_00a14ad9 = cVar6;
      DAT_00a14ae0 = cVar1;
    }
    puVar2 = (uint *)FUN_004ce990(1);
    if ((*puVar2 & 0x20) != 0) {
      DAT_00a14ada = cVar6;
      DAT_00a14ae1 = cVar1;
    }
    puVar2 = (uint *)FUN_004ce990(1);
    if ((*puVar2 & 0x40) != 0) {
      DAT_00a14adb = cVar6;
      DAT_00a14ae2 = cVar1;
    }
    puVar2 = (uint *)FUN_004ce990(1);
    if ((*puVar2 & 0x80) != 0) {
      DAT_00a14ad8 = cVar6;
      DAT_00a14adf = cVar1;
    }
  }
  else if (*puVar2 >> 0x1c == 1) {
    puVar2 = (uint *)FUN_004ce990(1);
    bVar7 = 1 - ((*puVar2 & 0x100) != 0);
    puVar2 = (uint *)FUN_004ce990(1);
    switch(*puVar2 & 0xf) {
    case 0:
      piVar3 = (int *)FUN_004ce990(2);
      if (*piVar3 == -1) {
        _memset(&DAT_00a149d5,(uint)bVar7,0x100);
      }
      else {
        puVar4 = (undefined4 *)FUN_004ce990(2);
        iVar5 = FUN_00487080(*puVar4);
        if (iVar5 + -100 < 0x100) {
          puVar4 = (undefined4 *)FUN_004ce990(2);
          local_18 = FUN_00487080(*puVar4);
          local_18 = local_18 + -100;
        }
        else {
          local_18 = 0xff;
        }
        if (local_18 < 0) {
          local_1c = 0;
        }
        else {
          puVar4 = (undefined4 *)FUN_004ce990(2);
          iVar5 = FUN_00487080(*puVar4);
          if (iVar5 + -100 < 0x100) {
            puVar4 = (undefined4 *)FUN_004ce990(2);
            local_20 = FUN_00487080(*puVar4);
            local_20 = local_20 + -100;
          }
          else {
            local_20 = 0xff;
          }
          local_1c = local_20;
        }
        (&DAT_00a149d5)[local_1c] = bVar7;
      }
      break;
    case 1:
      DAT_00a14ae3 = bVar7;
      break;
    case 2:
      DAT_00a14ae4 = bVar7;
      break;
    case 3:
      _memset(&DAT_00a149d5,(uint)bVar7,0x100);
      DAT_00a14ae3 = bVar7;
      DAT_00a14ae4 = bVar7;
    }
  }
  return;
}

