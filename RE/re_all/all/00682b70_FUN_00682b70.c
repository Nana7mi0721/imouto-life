
undefined4 FUN_00682b70(int *param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  puVar2 = (undefined4 *)param_1[6];
  pbVar5 = (byte *)*puVar2;
  iVar4 = puVar2[1];
  if (*(char *)(param_1[0x6b] + 0xd) == '\0') {
    *(undefined4 *)(*param_1 + 0x14) = 0x3c;
    _strncpy((char *)(*param_1 + 0x18),&DAT_00a0dc30,0x50);
    (**(code **)*param_1)(param_1);
  }
  if (2 < param_1[9]) {
    if (iVar4 == 0) {
      cVar3 = (*(code *)puVar2[3])(param_1);
      if (cVar3 == '\0') {
        return 0;
      }
      pbVar5 = (byte *)*puVar2;
      iVar4 = puVar2[1];
    }
    iVar4 = iVar4 + -1;
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 1;
    if (iVar4 == 0) {
      cVar3 = (*(code *)puVar2[3])(param_1);
      if (cVar3 == '\0') {
        return 0;
      }
      pbVar5 = (byte *)*puVar2;
      iVar4 = puVar2[1];
    }
    iVar4 = iVar4 + -1;
    pbVar6 = pbVar5 + 1;
    if (CONCAT11(bVar1,*pbVar5) != 0x18) {
      *(undefined4 *)(*param_1 + 0x14) = 0xc;
      (**(code **)*param_1)(param_1);
    }
    if (iVar4 == 0) {
      cVar3 = (*(code *)puVar2[3])(param_1);
      if (cVar3 == '\0') {
        return 0;
      }
      pbVar6 = (byte *)*puVar2;
      iVar4 = puVar2[1];
    }
    iVar4 = iVar4 + -1;
    pbVar7 = pbVar6 + 1;
    if (*pbVar6 != 0xd) {
      *(undefined4 *)(*param_1 + 0x14) = 0x46;
      *(int *)(*param_1 + 0x18) = param_1[0x65];
      (**(code **)*param_1)(param_1);
    }
    if (iVar4 == 0) {
      cVar3 = (*(code *)puVar2[3])(param_1);
      if (cVar3 == '\0') {
        return 0;
      }
      pbVar7 = (byte *)*puVar2;
      iVar4 = puVar2[1];
    }
    iVar4 = iVar4 + -1;
    bVar1 = *pbVar7;
    pbVar7 = pbVar7 + 1;
    if (iVar4 == 0) {
      cVar3 = (*(code *)puVar2[3])(param_1);
      if (cVar3 == '\0') {
        return 0;
      }
      pbVar7 = (byte *)*puVar2;
      iVar4 = puVar2[1];
    }
    iVar4 = iVar4 + -1;
    pbVar5 = pbVar7 + 1;
    if (CONCAT11(bVar1,*pbVar7) == 0xff) {
      if (iVar4 == 0) {
        cVar3 = (*(code *)puVar2[3])(param_1);
        if (cVar3 == '\0') {
          return 0;
        }
        pbVar5 = (byte *)*puVar2;
        iVar4 = puVar2[1];
      }
      iVar4 = iVar4 + -1;
      bVar1 = *pbVar5;
      pbVar5 = pbVar5 + 1;
      if (bVar1 == 3) {
        if (iVar4 == 0) {
          cVar3 = (*(code *)puVar2[3])(param_1);
          if (cVar3 == '\0') {
            return 0;
          }
          pbVar5 = (byte *)*puVar2;
          iVar4 = puVar2[1];
        }
        bVar1 = *pbVar5;
        iVar4 = iVar4 + -1;
        pbVar5 = pbVar5 + 1;
        if ((uint)bVar1 == *(uint *)(param_1[0x31] + 0x58)) {
          if (iVar4 == 0) {
            cVar3 = (*(code *)puVar2[3])(param_1);
            if (cVar3 == '\0') {
              return 0;
            }
            pbVar5 = (byte *)*puVar2;
            iVar4 = puVar2[1];
          }
          bVar1 = *pbVar5;
          iVar4 = iVar4 + -1;
          pbVar5 = pbVar5 + 1;
          if ((uint)bVar1 == *(uint *)param_1[0x31]) {
            if (iVar4 == 0) {
              cVar3 = (*(code *)puVar2[3])(param_1);
              if (cVar3 == '\0') {
                return 0;
              }
              pbVar5 = (byte *)*puVar2;
              iVar4 = puVar2[1];
            }
            bVar1 = *pbVar5;
            iVar4 = iVar4 + -1;
            pbVar5 = pbVar5 + 1;
            if ((uint)bVar1 == *(uint *)(param_1[0x31] + 0xb0)) {
              if (iVar4 == 0) {
                cVar3 = (*(code *)puVar2[3])(param_1);
                if (cVar3 == '\0') {
                  return 0;
                }
                pbVar5 = (byte *)*puVar2;
                iVar4 = puVar2[1];
              }
              iVar4 = iVar4 + -1;
              bVar1 = *pbVar5;
              pbVar5 = pbVar5 + 1;
              if (bVar1 == 0x80) {
                if (iVar4 == 0) {
                  cVar3 = (*(code *)puVar2[3])(param_1);
                  if (cVar3 == '\0') {
                    return 0;
                  }
                  pbVar5 = (byte *)*puVar2;
                  iVar4 = puVar2[1];
                }
                iVar4 = iVar4 + -1;
                bVar1 = *pbVar5;
                pbVar6 = pbVar5 + 1;
                if (iVar4 == 0) {
                  cVar3 = (*(code *)puVar2[3])(param_1);
                  if (cVar3 == '\0') {
                    return 0;
                  }
                  pbVar6 = (byte *)*puVar2;
                  iVar4 = puVar2[1];
                }
                iVar4 = iVar4 + -1;
                pbVar5 = pbVar6 + 1;
                if (CONCAT11(bVar1,*pbVar6) == 0) {
                  if (iVar4 == 0) {
                    cVar3 = (*(code *)puVar2[3])(param_1);
                    if (cVar3 == '\0') {
                      return 0;
                    }
                    pbVar5 = (byte *)*puVar2;
                    iVar4 = puVar2[1];
                  }
                  iVar4 = iVar4 + -1;
                  bVar1 = *pbVar5;
                  pbVar6 = pbVar5 + 1;
                  if (iVar4 == 0) {
                    cVar3 = (*(code *)puVar2[3])(param_1);
                    if (cVar3 == '\0') {
                      return 0;
                    }
                    pbVar6 = (byte *)*puVar2;
                    iVar4 = puVar2[1];
                  }
                  iVar4 = iVar4 + -1;
                  pbVar5 = pbVar6 + 1;
                  if (CONCAT11(bVar1,*pbVar6) == 0) {
                    if (iVar4 == 0) {
                      cVar3 = (*(code *)puVar2[3])(param_1);
                      if (cVar3 == '\0') {
                        return 0;
                      }
                      pbVar5 = (byte *)*puVar2;
                      iVar4 = puVar2[1];
                    }
                    iVar4 = iVar4 + -1;
                    bVar1 = *pbVar5;
                    pbVar5 = pbVar5 + 1;
                    if (bVar1 == 0) {
                      if (iVar4 == 0) {
                        cVar3 = (*(code *)puVar2[3])(param_1);
                        if (cVar3 == '\0') {
                          return 0;
                        }
                        pbVar5 = (byte *)*puVar2;
                        iVar4 = puVar2[1];
                      }
                      iVar4 = iVar4 + -1;
                      bVar1 = *pbVar5;
                      pbVar6 = pbVar5 + 1;
                      if (iVar4 == 0) {
                        cVar3 = (*(code *)puVar2[3])(param_1);
                        if (cVar3 == '\0') {
                          return 0;
                        }
                        pbVar6 = (byte *)*puVar2;
                        iVar4 = puVar2[1];
                      }
                      iVar4 = iVar4 + -1;
                      pbVar5 = pbVar6 + 1;
                      if (CONCAT11(bVar1,*pbVar6) == 1) {
                        if (iVar4 == 0) {
                          cVar3 = (*(code *)puVar2[3])(param_1);
                          if (cVar3 == '\0') {
                            return 0;
                          }
                          pbVar5 = (byte *)*puVar2;
                          iVar4 = puVar2[1];
                        }
                        iVar4 = iVar4 + -1;
                        bVar1 = *pbVar5;
                        pbVar6 = pbVar5 + 1;
                        if (iVar4 == 0) {
                          cVar3 = (*(code *)puVar2[3])(param_1);
                          if (cVar3 == '\0') {
                            return 0;
                          }
                          pbVar6 = (byte *)*puVar2;
                          iVar4 = puVar2[1];
                        }
                        iVar4 = iVar4 + -1;
                        pbVar5 = pbVar6 + 1;
                        if (CONCAT11(bVar1,*pbVar6) == 0) {
                          if (iVar4 == 0) {
                            cVar3 = (*(code *)puVar2[3])(param_1);
                            if (cVar3 == '\0') {
                              return 0;
                            }
                            pbVar5 = (byte *)*puVar2;
                            iVar4 = puVar2[1];
                          }
                          iVar4 = iVar4 + -1;
                          bVar1 = *pbVar5;
                          pbVar5 = pbVar5 + 1;
                          if (bVar1 == 0) {
                            if (iVar4 == 0) {
                              cVar3 = (*(code *)puVar2[3])(param_1);
                              if (cVar3 == '\0') {
                                return 0;
                              }
                              pbVar5 = (byte *)*puVar2;
                              iVar4 = puVar2[1];
                            }
                            iVar4 = iVar4 + -1;
                            bVar1 = *pbVar5;
                            pbVar6 = pbVar5 + 1;
                            if (iVar4 == 0) {
                              cVar3 = (*(code *)puVar2[3])(param_1);
                              if (cVar3 == '\0') {
                                return 0;
                              }
                              pbVar6 = (byte *)*puVar2;
                              iVar4 = puVar2[1];
                            }
                            iVar4 = iVar4 + -1;
                            pbVar5 = pbVar6 + 1;
                            if (CONCAT11(bVar1,*pbVar6) == 1) {
                              if (iVar4 == 0) {
                                cVar3 = (*(code *)puVar2[3])(param_1);
                                if (cVar3 == '\0') {
                                  return 0;
                                }
                                pbVar5 = (byte *)*puVar2;
                                iVar4 = puVar2[1];
                              }
                              iVar4 = iVar4 + -1;
                              bVar1 = *pbVar5;
                              pbVar6 = pbVar5 + 1;
                              if (iVar4 == 0) {
                                cVar3 = (*(code *)puVar2[3])(param_1);
                                if (cVar3 == '\0') {
                                  return 0;
                                }
                                pbVar6 = (byte *)*puVar2;
                                iVar4 = puVar2[1];
                              }
                              iVar4 = iVar4 + -1;
                              pbVar5 = pbVar6 + 1;
                              if (CONCAT11(bVar1,*pbVar6) == 0) goto LAB_00682fc3;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  *(undefined4 *)(*param_1 + 0x14) = 0x1c;
  (**(code **)*param_1)(param_1);
LAB_00682fc3:
  param_1[0x43] = 1;
  *puVar2 = pbVar5;
  puVar2[1] = iVar4;
  return 1;
}

