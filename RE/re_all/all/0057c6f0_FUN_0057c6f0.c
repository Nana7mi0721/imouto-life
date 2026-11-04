
undefined4 FUN_0057c6f0(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint in_EAX;
  int iVar4;
  int iVar5;
  undefined4 local_8;
  
  local_8 = 0;
  if (DAT_00ca3cd8 == 0) {
    return 0xffffffff;
  }
  FUN_0056da60(&DAT_00cc6284,"..\\..\\..\\..\\Source\\Library\\Main\\DxNetwork.cpp",0x7a1);
  if (((((DAT_00cc6240 == 0) || ((int)in_EAX < 0)) || ((in_EAX & 0x7c000000) != DAT_00cc6268)) ||
      (((DAT_00cc6270 <= (int)(in_EAX & 0xffff) ||
        (piVar3 = *(int **)(DAT_00cc6244 + (in_EAX & 0xffff) * 4), piVar3 == (int *)0x0)) ||
       ((*piVar3 * 0x10000 != (in_EAX & 0x3ff0000) || ((piVar3[4] != 0 || (piVar3[0xc] != 0))))))))
     || (DAT_00ca3d10 == 1)) {
    FUN_0056dac0(&DAT_00cc6284);
    return 0xffffffff;
  }
  DAT_00ca3d10 = 1;
  FUN_0057bf50(0);
  if (piVar3[0xe] == 0) {
    FUN_0056bb10(&DAT_007d84f8);
    local_8 = 0xffffffff;
  }
  else if (piVar3[0x10] == 1) {
    FUN_0056bb10(&DAT_007d84a0);
    local_8 = 0xffffffff;
  }
  else if (piVar3[0x24] == 0) {
    local_8 = 0;
  }
  else if (piVar3[0x16] == 1) {
    do {
      iVar4 = piVar3[0x27];
      if (iVar4 != 0) {
        iVar4 = (*DAT_00aba0fc)(piVar3[0x18],(int)piVar3 + (0x9c - iVar4),iVar4,0);
        if (iVar4 < 0) break;
        piVar1 = piVar3 + 0x27;
        *piVar1 = *piVar1 - iVar4;
        if (*piVar1 != 0) break;
      }
      piVar1 = piVar3 + 0x26;
      if (piVar3[0x26] == 0) {
        *piVar1 = piVar3[0x24];
        iVar4 = (*DAT_00aba0fc)(piVar3[0x18],piVar1,4,0);
        if (iVar4 < 0) {
          piVar3[0x26] = 0;
          break;
        }
        if (iVar4 < 4) {
          piVar3[0x27] = 4 - iVar4;
          break;
        }
      }
      piVar2 = piVar3 + 0x21;
      FUN_0057beb0(piVar2);
      iVar4 = piVar3[0x22];
      if (piVar3[0x25] < iVar4 + *piVar1) {
        iVar5 = (*DAT_00aba0fc)(piVar3[0x18],*piVar2 + iVar4,piVar3[0x25] - iVar4);
        if (iVar5 < 0) break;
        if (iVar5 < piVar3[0x25] - piVar3[0x22]) {
          piVar3[0x22] = piVar3[0x22] + iVar5;
          iVar4 = iVar5;
        }
        else {
          iVar4 = (*DAT_00aba0fc)(piVar3[0x18],*piVar2,*piVar1 - iVar5,0);
          if (iVar4 < 0) {
            piVar3[0x22] = 0;
            iVar4 = iVar5;
          }
          else if (iVar4 == *piVar1 - iVar5) {
            piVar3[0x22] = iVar4;
            iVar4 = iVar4 + iVar5;
          }
        }
      }
      else {
        iVar4 = (*DAT_00aba0fc)(piVar3[0x18],*piVar2 + iVar4,*piVar1,0);
        if (iVar4 < 0) break;
        piVar3[0x22] = piVar3[0x22] + iVar4;
      }
      piVar3[0x24] = piVar3[0x24] - iVar4;
      *piVar1 = *piVar1 - iVar4;
      iVar5 = FUN_0057bf50(0);
      if ((((iVar5 != 0) || (iVar4 == 0)) || (*piVar1 != 0)) || (piVar3[0x24] == 0)) break;
    } while( true );
  }
  DAT_00ca3d10 = 0;
  FUN_0056dac0(&DAT_00cc6284);
  return local_8;
}

